#include "mbed.h"

void OnRxchar(); //cada vez que recibe un caracter salta a esta interrupcion 
int DecodeHeader(uint8_t index); //Me devuelve 1 si la cabecera va bien , 0 si hay algun error
void decodeData(uint8_t index);
void SendInfo(uint8_t bufferAux[], uint8_t bytes);
void ServOnMove();
void HeartBeat();
void TimingDistance();
void Paning();
void MoverServo(int8_t Ang);
void distanceMeasurement();
void distanceInitMeasurement();
void Motores(int16_t VelM1,int8_t SentidoM1,int16_t VelM2,int8_t SentidoM2);
void SENSORIR();
void SigueMano();
void pulsador();

typedef union{
    uint8_t     u8[4];
    int8_t      i8[4];
    uint16_t    u16[2];
    int16_t     i16[2];
    uint32_t    u32;
    int32_t     i32;
}_work;

typedef union{
    uint8_t     u8[2];
    uint16_t    u16;
}_work1;

typedef struct {
    uint16_t IR1;
    uint16_t IR2;
    uint16_t IR3;
}IRSen;

typedef enum{
    ALIVE=0xF0,
    FIRMWARE=0xF1,
    LEDS=0x10,
    PULSADORES=0x12,
    SERVO=0xA2,
    DISTANCIA=0xA3,
    NEGROIR=0xA6,
    BLANCOIR=0xA7,
    PANEO=0xA8,
    TESTMOTOR=0xA1,
} _eEstadoMEFcmd;

typedef enum{
    IDLE=0,
    SIGUEMANO=1,
    SIGUELINEA=2,
    LABERINTO=3,
} _eGameSelect;

typedef enum{
    MOVING=0,
    SEARCHING=1,
    DERIVA=2,
    COMPROBAR=3,
} _eGame1State;

typedef enum{
    FALLING,
    RISING,
    UP,
    DOWN,
} _eButtonState;

DigitalOut LED(PC_13);
RawSerial Pc(PA_9,PA_10);
DigitalIn Pulsador(PA_4);
// BusOut Leds(PB_6,PB_7,PB_14,PB_15);

DigitalOut trigger(PB_13);
InterruptIn hecho(PB_12);
PwmOut servo(PA_8);

//MANEJO MOTOR IZQUIERDO
PwmOut M1(PB_1);
DigitalOut In1M1(PB_15);
DigitalOut In2M1(PB_14);

//MANEJO MOTOR DERECHO
PwmOut M2(PB_0);
DigitalOut In3M2(PB_6);
DigitalOut In4M2(PB_7);

//MANEJO SEGUIDORES DE LINEA
AnalogIn irIz(PA_0);
AnalogIn irC(PA_1);
AnalogIn irDr(PA_2);

Timer myTimer;
IRSen Irval;
_eButtonState BUTTON=UP;
_eGameSelect GAME=IDLE;
_work w;
_work1 w1;
volatile uint8_t rxData[256],RindexW,RindexR; //tdo lo que se usa como interrupcion deberia ser volatile ,este es el buffer
volatile uint8_t txData[256],TindexW,TindexR;
uint8_t ID, length, cks;
int8_t angaux=0;
bool Servomov=false,echo=false,measuring=false,PanOn=false;
//contadores
int32_t timeS=0,timeSEN=0;
uint32_t counter2=0,timeaux=0,delay=0,counter3=0,counterSERV=0,counterSearch=0,counterPulsador=0,counterCambioJuego=0;
//VARIABLES MOTORES
int16_t VelM1=0,VelM2=0;
int8_t SentidoM1=0,SentidoM2=0;

int main(){

    myTimer.start();
    TindexR=0;
    TindexW=0;

    M2.period_us(25000);
    M1.period_us(25000);

    servo.period_ms(20);
    trigger.write(false);
    // hecho.rise(&distanceInitMesurement);
    // hecho.fall(&distanceMensurement);
    Pc.baud(115200); //protocolo para pasarle info al micro t=1/11520
    Pc.attach(&OnRxchar,SerialBase::RxIrq); //interrupcion para llamar al onrxchar

    //PRUEBA DE FUNCIONAMIETNO SENSORES Y MOTORES
    servo.pulsewidth_us(2440);
    wait_ms(450);
    //DIRECCION
    In1M1.write(1);
    In2M1.write(0);
    //POTENCIA
    M1.pulsewidth_us(25000);

    In3M2.write(0);
    In4M2.write(1);
    M2.pulsewidth_us(25000);

    servo.pulsewidth_us(460);
    wait_ms(450);

    In1M1.write(0);
    In2M1.write(0);
    M1.pulsewidth_us(0);
    In3M2.write(0);
    In4M2.write(0);
    M2.pulsewidth_us(0);

    servo.pulsewidth_us(1450);

    hecho.rise(&distanceInitMeasurement);
    hecho.fall(&distanceMeasurement);

    uint8_t GameHeartbeat=0;

    while(1){
        
        HeartBeat();

        // if((myTimer.read_ms()-counterPulsador)>40){
        //     counterPulsador=myTimer.read_ms();
        //     pulsador();
        // }

        // if(BUTTON == DOWN ){

        //     if((myTimer.read_ms()-counterCambioJuego)>1000 && (myTimer.read_ms()-counterCambioJuego)<5000){

        //         counterCambioJuego=myTimer.read_ms();

        //         GameHeartbeat++;

        //         if(GameHeartbeat>4)
        //             GameHeartbeat=0;

        //         switch (GameHeartbeat){
        //             case 0:
        //                 GAME=IDLE;
        //             break;
        //             case 1:
        //                 GAME=SIGUEMANO;
        //             break;
        //             case 2:
        //                 GAME=IDLE;
        //             break;
        //             case 3:
        //                 GAME=IDLE;
        //             break;
        //         }
        //     }
        // }
        //Si los indices son diferentes, Decodifico lo que llego por el puerto Serie
        if(RindexR!=RindexW)
            DecodeHeader(RindexW);
        
        //Si los indices son diferentes, envío lo que hay por el puerto Serie si está disponible(writeable)
        if(TindexR!=TindexW){
            if(Pc.writeable())
                Pc.putc(txData[TindexR++]);
        }

        if(Servomov)
            ServOnMove();

    //    SENSORIR();
        TimingDistance();


        SigueMano();
        // switch(GAME){
            
        //     case IDLE:
        //     break;
        //     case SIGUEMANO:
        //         SigueMano();
        //     break;
        //     case SIGUELINEA:
        //     break;
        //     case LABERINTO:
        //     break;
            
        // }

        // if(PanOn)
        //     Paning();
    }
}

void ServOnMove(){

    if((myTimer.read_ms()-counter2)>(timeaux+50)){
        counter2=myTimer.read_ms();
        rxData[RindexW]=SERVO;
        decodeData(RindexW);
        Servomov=false;
    }
}

void HeartBeat(){

    static uint8_t move=0;
    static uint32_t counter=0;
    uint8_t mask=21;
    uint32_t comp=31; //comp para comparar en bitwise
    

    switch (GAME){
        case IDLE:
            mask=5;
            comp=0x0F;
        break;
        case SIGUEMANO:
            // mask=0x5F;      //0101 1111
            // comp=0x7FFFFFFF; //30 1 (un monton de 1)
            mask=1;
            comp=0x01;
        break;
        case SIGUELINEA:
        break;
        case LABERINTO:
        break;

    }
    if((myTimer.read_ms()-counter)>100){
        counter=myTimer.read_ms();
        LED.write( (~mask) & (1<<move));
        move++;
        move&=comp;
    }
}

void OnRxchar(){
    while(Pc.readable()){ //recibe los datos y los guarda en el buffer si tiene espacio en el mbed
        rxData[RindexW++]=Pc.getc();
    }
}

int DecodeHeader(uint8_t index){
    
    static uint8_t header = 0, ind=0;

    while (RindexR != index)
    {
        switch (header)
        {
        case 0:
            if(rxData[RindexR]=='U')
                header=1;
            break;
        case 1:
            if(rxData[RindexR]=='N')
            header=2;
            else{
                header=0;
                RindexR--;
            }
            break;
        case 2:
            if(rxData[RindexR]=='E')
            header=3;
            else{
                header=0;
                RindexR--;
            }
            break;
        case 3:
            if(rxData[RindexR]=='R')
            header=4;
            else{
                header=0;
                RindexR--;
            }
            break;
        case 4:
            length = rxData[RindexR];
            header=5;
            break;
        case 5:
            if(rxData[RindexR]==':'){
            ind=RindexR+1;// me quedo con la posición en donde está el ID
            header=6;
            cks = 'U' ^ 'N' ^ 'E' ^ 'R' ^ length ^ ':';
            }else{
                header=0;
                RindexR--;
            }
            break;
        case 6:
            length--;
            if(length!=0)
                cks ^= rxData[RindexR];
            else{
                if(cks ==rxData[RindexR])
                    decodeData(ind);
                header=0;
                RindexR--;
            }
            break;
            default:
                header=0;
                break;
        }

        RindexR++;
    }
    return 0;
}

void decodeData(uint8_t index){

    uint8_t bufAux[20], indiceAux=0;
    #define NBYTES  4
    bufAux[indiceAux++]='U';
    bufAux[indiceAux++]='N';
    bufAux[indiceAux++]='E';
    bufAux[indiceAux++]='R';
    bufAux[indiceAux++]=0;
    bufAux[indiceAux++]=':';

    switch (rxData[index])
    {
    case ALIVE:
      
        bufAux[indiceAux++]=ALIVE;
        bufAux[indiceAux++]=0x0D;
        bufAux[NBYTES]=0x03;    
       
        break;
    case FIRMWARE:

        bufAux[indiceAux++]=FIRMWARE;
        bufAux[indiceAux++]=0xF1;
        bufAux[NBYTES]=0x03; 

        break;
    case LEDS:
      
        // bufAux[indiceAux++]=LEDS;
        // bufAux[indiceAux++]=Leds.read();
        // bufAux[NBYTES]=0x03;
       
        break;
    case PULSADORES:
       
        bufAux[indiceAux++]=PULSADORES;
        bufAux[indiceAux++]=Pulsador.read();
        bufAux[NBYTES]=0x03; 
      
        break;
    case SERVO:

        bufAux[indiceAux++]=SERVO;

        if(!Servomov){

            bufAux[indiceAux++]=0x0D;
            w.i8[0]=(rxData[index+1]);
            MoverServo(w.i8[0]);

        }else   
            bufAux[indiceAux++]=0x0A;

        bufAux[NBYTES]=0x03;
        break;
    case DISTANCIA:

        bufAux[indiceAux++]=DISTANCIA;
        if(w.u32/58 < 150 ){
            for(int i=0;i<4;i++)
                bufAux[indiceAux++]=w.u8[i];
        }else{
            for(int i=0;i<4;i++)
                bufAux[indiceAux++]=0;
        }
        bufAux[NBYTES]=0x06;

        break;
    case PANEO:
        PanOn=true;
        counter3= myTimer.read_ms();
        counterSERV= myTimer.read_ms();
        bufAux[indiceAux++]=PANEO;
        bufAux[indiceAux++]=0x0D;
        bufAux[NBYTES]=0x03;

    break;
    case TESTMOTOR:

        bufAux[indiceAux++]=TESTMOTOR;
        bufAux[indiceAux++]=0x0D;
        bufAux[NBYTES]=0x03;

        VelM1=rxData[index+1];
        SentidoM1=rxData[index+2];
        VelM2=rxData[index+3];
        SentidoM2=rxData[index+4];

        Motores(VelM1,SentidoM1,VelM2,SentidoM2);

    break;
    case NEGROIR:

        Irval.IR1=irIz.read();
        Irval.IR2=irC.read();
        Irval.IR3=irDr.read();

        bufAux[indiceAux++]=NEGROIR;

        w1.u16=Irval.IR1;
        bufAux[indiceAux++]=w.u8[0];
        bufAux[indiceAux++]=w.u8[1];

        w1.u16=Irval.IR2;
        bufAux[indiceAux++]=w.u8[0];
        bufAux[indiceAux++]=w.u8[1];

        w1.u16=Irval.IR3;
        bufAux[indiceAux++]=w.u8[0];
        bufAux[indiceAux++]=w.u8[1];

        bufAux[NBYTES]=0x08;
        //SENSORIR();
    break;
    case BLANCOIR:
        
        Irval.IR1=irIz.read();
        Irval.IR2=irC.read();
        Irval.IR3=irDr.read();

        bufAux[indiceAux++]=BLANCOIR;

        w1.u16=Irval.IR1;
        bufAux[indiceAux++]=w.u8[0];
        bufAux[indiceAux++]=w.u8[1];

        w1.u16=Irval.IR2;
        bufAux[indiceAux++]=w.u8[0];
        bufAux[indiceAux++]=w.u8[1];

        w1.u16=Irval.IR3;
        bufAux[indiceAux++]=w.u8[0];
        bufAux[indiceAux++]=w.u8[1];

        bufAux[NBYTES]=0x08;

    break;
    default:
       
        bufAux[indiceAux++]=0xFF;
        bufAux[NBYTES]=0x02;    
       
        break;
    }
    cks=0;
    for(uint8_t i=0 ;i<indiceAux;i++){
     
        cks^= bufAux[i];
        txData[TindexW++]=bufAux[i];
   
    }
    
    txData[TindexW++]=cks;
}

void distanceInitMeasurement(){
    timeSEN=myTimer.read_us();
}

void distanceMeasurement(){
    
    timeS=myTimer.read_us();

    if(timeS<timeSEN)
        timeS = timeS- timeSEN + 0xFFFFFFFF; 
    else    
        timeS=  timeS -timeSEN ;

    w.u32=timeS;
}

void TimingDistance(){

    if((myTimer.read_us() - delay) > 100000 ){
        delay = myTimer.read_us();
        measuring=false;
    }

    if(!measuring){
  
        if((myTimer.read_us() - delay)>10){
            delay = myTimer.read_us();
            trigger.write(0);
            measuring=true;
        }else
        trigger.write(1);
    }
}

void Paning(){

    static uint8_t i,Distances[18];

    servo.pulsewidth_us(460+(110*i));

    if((myTimer.read_ms() - counterSERV) > 18 ){ //demora del servoen ubicarse

        counterSERV=myTimer.read_ms();

        if((myTimer.read_ms() - counter3) > 200 ){ //maximo de 200 milisewgundos para volver a medir

            counter3=myTimer.read_ms();
            
            if((w.u32/58)<150){
                Distances[0]=PANEO;
                Distances[1]=w.u8[0];
                Distances[2]=w.u8[1];
                Distances[3]=w.u8[2];
                Distances[4]=w.u8[3];
            }else{
                Distances[0]=PANEO;
                Distances[1]=0;
                Distances[2]=0;
                Distances[3]=0;
                Distances[4]=0;
            }
            SendInfo(Distances,6);
            i++;
        }
    }
    if(i==18){
        servo.pulsewidth_us(1440);
        i=0;
        PanOn=false;
    }
    
}

void MoverServo(int8_t Ang){
   
    counter2=myTimer.read_ms(); //tomo el tiempo cuando le paso la orden de moverse, para cualcular el tiempo que demora en moverse

    w.u32=(Ang*11)+1450; //conversion para lso grados del servo
    servo.pulsewidth_us(w.u32);

    angaux-=Ang;
    timeaux=abs((angaux*10)/6); //calulo del tiempo que se tarda en mover el servo
    Servomov=true;

}

void SendInfo(uint8_t bufferAux[], uint8_t bytes){
    uint8_t bufAux[20], indiceAux=0;
    #define NBYTES  4
    bufAux[indiceAux++]='U';
    bufAux[indiceAux++]='N';
    bufAux[indiceAux++]='E';
    bufAux[indiceAux++]='R';
    bufAux[indiceAux++]=0;
    bufAux[indiceAux++]=':';
    for(uint8_t i=0; i<bytes-1; i++){
        bufAux[indiceAux++] = bufferAux[i];
    }
    bufAux[NBYTES] = bytes;
    cks=0;
    for(uint8_t i=0 ;i<indiceAux;i++){
        cks^= bufAux[i];
        txData[TindexW++]=bufAux[i];
    }
     txData[TindexW++]=cks;
}

void Motores(int16_t VelM1,int8_t SentidoM1,int16_t VelM2,int8_t SentidoM2){ //sent =1 AVANZA HACIA DELANTE 0 hacia atras

    if(SentidoM1==0){
        In1M1.write(1);
        In2M1.write(0);
    }else{
        In1M1.write(0);
        In2M1.write(1);
    }
    M1.pulsewidth_us(abs(VelM1)*250);

     if(SentidoM2==0){
        In3M2.write(1);
        In4M2.write(0);
    }else{
        In3M2.write(0);
        In4M2.write(1);
    }
    M2.pulsewidth_us(abs(VelM2)*240); //motor derecho tiene mas fuerza que el izquierdo
}

void SigueMano(){

    static _eGame1State STATE;
    static int8_t AngSearch = -90;
    uint8_t Distance;

    Distance=timeS/58;

    switch (STATE){

        case MOVING:

            if((Distance)<11 && (Distance)>9) //si esta entre 9 y 11 el auto frena
                Motores(0,0,0,0);
            else
            if((Distance)<4)
                Motores(0,0,0,0);
            else
            if((Distance)<20 && (Distance)>11)
                Motores(40,0,40,0);
            else
            if((Distance)<40 && (Distance)>20)
                Motores(100,0,100,0);
            else
            if((Distance)<9)
                Motores(100,1,100,1);
            else
            if((Distance)<15 && (Distance)>9)
                Motores(40,1,40,1);
            if((Distance)>40){
                Motores(0,0,0,0);
            }
            
        break;
    
        case SEARCHING:

            MoverServo(AngSearch);

            if((myTimer.read_ms()-counterSearch)>250){ //tiempo en ubicar el servo y medir la distancia 
                
                counterSearch=myTimer.read_ms();
            
                AngSearch+=10;

                if((Distance)<40){
                    MoverServo(0);
                    STATE=DERIVA;
                    AngSearch=-90;
                }
            }
            
        break;
        case DERIVA:

            if(AngSearch<0)
                Motores(40,1,40,0);
            else
                Motores(40,0,40,1);

            STATE=COMPROBAR;
            counterSearch=myTimer.read_ms();

        break;
        case COMPROBAR:

            if((myTimer.read_ms()-counterSearch)>250){
                counterSearch=myTimer.read_ms();
                Motores(0,0,0,0);

                if((Distance)<40)
                    STATE=MOVING;
                else    
                    STATE=SEARCHING;
            }
        break;
    }
}

void pulsador(){

    bool BUT;
    BUT = Pulsador.read();    
    
    switch (BUTTON){
        case UP:
            if(BUT)  //boton presionado == 0
                BUTTON = FALLING;
        break;

        case DOWN:
            if(!BUT)
                BUTTON = RISING;
        break;

        case FALLING:
            if(BUT)
                BUTTON = DOWN;
            else   
                BUTTON = UP;
        break;

        case RISING:
            if(!BUT)
                BUTTON = UP;
            else    
                BUTTON = DOWN;
        break;
  
    }
}
// void SENSORIR(){

//     uint8_t bufAux[10];

//     Irval.IR1=irIz.read();
//     Irval.IR2=irC.read();
//     Irval.IR3=irDr.read();

//     bufAux[0]=NEGROIR;

//     w1.u16=Irval.IR1;
//     bufAux[1]=w.u8[0];
//     bufAux[2]=w.u8[1];

//     w1.u16=Irval.IR2;
//     bufAux[3]=w.u8[0];
//     bufAux[4]=w.u8[1];

//     w1.u16=Irval.IR3;
//     bufAux[5]=w.u8[0];
//     bufAux[6]=w.u8[1];

// }