#include "qform1.h"
#include "ui_qform1.h"

QForm1::QForm1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QForm1)
{
    ui->setupUi(this);

    this->setWindowTitle("RADAR ULTRASONICO");

    QSerialPort1=new QSerialPort(this);

    QPaintBox1 = new QPaintBox(0, 0, ui->ACTIVERADAR);

//    ui->ACTIVERADAR->setStyleSheet(back)
    ui->comboBox->installEventFilter(this);

    ui->comboBox_2->addItem("ALIVE", 0xF0);
    ui->comboBox_2->addItem("FIRMWARE", 0xF1);
    ui->comboBox_2->addItem("LEDS", 0x10);
    ui->comboBox_2->addItem("PULSADORES", 0x12);
    ui->comboBox_2->addItem("TEST MOTOR", 0xA1);
    ui->comboBox_2->addItem("SERVO", 0xA2);
    ui->comboBox_2->addItem("DISTANCIA",0xA3);
    ui->comboBox_2->addItem("VEL.MOTOR",0xA4);
    ui->comboBox_2->addItem("BLANCOIR",0xA7);
    ui->comboBox_2->addItem("NEGROIR",0xA6);
    ui->comboBox_2->addItem("PANEO",0xA8);
    header=0;
    connect(QSerialPort1,&QSerialPort::readyRead, this,&QForm1::OnRxChar);

    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &QForm1::OnQTimer1);
    QTimer1->start(10);
//    radar = new Radar(this);
//    connect(radar, &Radar::Points, this, &QForm1::pasoPuntos);
//    radar->setWindowTitle("RADAR");
//    radar->hide();

}

QForm1::~QForm1()
{
    delete ui;
    delete QPaintBox1;

}

bool QForm1::eventFilter(QObject *watched, QEvent *event){
    if(watched == ui->comboBox) {
        if (event->type() == QEvent::MouseButtonPress) {
            ui->comboBox->clear();
            QSerialPortInfo SerialPortInfo1;

            for(int i=0;i<SerialPortInfo1.availablePorts().count();i++)
                ui->comboBox->addItem(SerialPortInfo1.availablePorts().at(i).portName());

            return QMainWindow::eventFilter(watched, event);
        }
        else {
            return false;
        }
    }
    else{
         return QMainWindow::eventFilter(watched, event);
    }
}

void QForm1::OnRxChar(){
    int count;
    uint8_t *buf;
    QString strHex;

    count = QSerialPort1->bytesAvailable();
    if(count <= 0)
        return;

    buf = new uint8_t[count];
    QSerialPort1->read((char *)buf, count);

    strHex = "<-- 0x";
    for (int a=0; a<count; a++) {
        strHex = strHex + QString("%1").arg(buf[a], 2, 16, QChar('0')).toUpper();
    }
     ui->plainTextEdit->appendPlainText(strHex);
    for (int i=0; i<count; i++) {
        strHex = strHex + QString("%1").arg(buf[i], 2, 16, QChar('0')).toUpper();

        switch(header){
        case 0:
            if(buf[i] == 'U'){
                header = 1;
                tmoRX = 5;
            }
            break;
        case 1:
            if(buf[i] == 'N')
                header = 2;
            else{
                header = 0;
                i--;
            }
            break;
        case 2:
            if(buf[i] == 'E')
                header = 3;
            else{
                header = 0;
                i--;
            }
            break;
        case 3:
            if(buf[i] == 'R')
                header = 4;
            else{
                header = 0;
                i--;
            }
            break;
        case 4:
            nBytes = buf[i];
            header = 5;
            break;
        case 5:
            if(buf[i] == ':'){
                header = 6;
                index = 0;
                cks = 'U' ^ 'N' ^ 'E' ^ 'R' ^ ':' ^ nBytes;
            }
            else{
                header = 0;
                i--;
            }
            break;
        case 6:
            nBytes--;
            if(nBytes > 0){
                rxBuf[index++] = buf[i];
                cks ^= buf[i];
            }
            else{
                header = 0;
                if(cks == buf[i])
                    DecodeCmd(rxBuf);
                else{
                    ui->plainTextEdit->appendPlainText("ERROR CHECKSUM");
                }
            }
            break;
        }
    }
    delete [] buf;
}

void QForm1::OnQTimer1(){

    uint8_t buf[1];
    buf[0]=0xA6;

    if(BanRad){
        DrawRadar();
        ActiveLine();
    }
    if(DirectOn)
       DirectComunication();
//    SendCMD(buf,2);
}

void QForm1::SendCMD(uint8_t *buf, uint8_t length){
    uint8_t tx[24];
    uint8_t cks, i;
    QString strHex;

    if(!QSerialPort1->isOpen())
        return;

    tx[0] = 'U';
    tx[1] = 'N';
    tx[2] = 'E';
    tx[3] = 'R';
    tx[4] = length + 1;
    tx[5] = ':';

    memcpy(&tx[6], buf, length);

    cks = 0;
    for (i=0; i<(length+6); i++) {
        cks ^= tx[i];
    }

    tx[i] = cks;

    strHex = "--> 0x";
    for (int i=0; i<length+7; i++) {
        strHex = strHex + QString("%1").arg(tx[i], 2, 16, QChar('0')).toUpper();
    }

    ui->plainTextEdit->appendPlainText(strHex);

    QSerialPort1->write((char *)tx, length+7);
}


void QForm1::on_pushButton_clicked()
{
    if(QSerialPort1->isOpen()){
        QSerialPort1->close();
        ui->pushButton->setText("OPEN");
    }
    else{
        if(ui->comboBox->currentText() == "")
            return;

        QSerialPort1->setPortName(ui->comboBox->currentText());
        QSerialPort1->setBaudRate(115200);
        QSerialPort1->setParity(QSerialPort::NoParity);
        QSerialPort1->setDataBits(QSerialPort::Data8);
        QSerialPort1->setStopBits(QSerialPort::OneStop);
        QSerialPort1->setFlowControl(QSerialPort::NoFlowControl);

        if(QSerialPort1->open(QSerialPort::ReadWrite)){
            ui->pushButton->setText("CLOSE");
        }
        else
            QMessageBox::information(this, "Serial PORT", "ERROR. Opening PORT");
    }
}


void QForm1::on_pushButton_3_clicked()
{
    ui->plainTextEdit->clear();
}


void QForm1::on_pushButton_2_clicked()
{
    uint8_t cmd,buf[24];
    int n;

    if(ui->comboBox_2->currentText() == "")
        return;

    cmd = ui->comboBox_2->currentData().toInt();
    ui->plainTextEdit->appendPlainText("0x" + (QString("%1").arg(cmd, 2, 16, QChar('0'))).toUpper());

    n = 0;
    switch (cmd) {
        case ALIVE://ALIVE   PC=>MBED 0xF0 ;  MBED=>PC 0xF0 0x0D
            n = 1;
            break;
        case FIRMWARE://FIRMWARE   PC=>MBED 0xF1 ;  MBED=>PC 0xF1 FIRMWARE
            n = 1;
            break;
        case LEDS://LEDS   PC=>MBED 0x10 LEDS_A_MODIFICAR VALOR_LEDS ;  MBED=>PC 0x10 ESTADO_LEDS
            n = 3;
            break;
        case PULSADORES://PULSADORES   PC=>MBED 0x12 ;  MBED=>PC 0x12 VALOR PULSADORES
            n = 1;
            break;
        case SERVO: //SERVO Pc=>MBED 0xA2 PASO ANGULO; MBED =>Pc 0xA2 VUELVE ANGULO
            Ang = QInputDialog::getInt(this, "SERVO", "Angulo",0,-90,90,1,&ok);

            if(!ok)
                break;

            buf[1]=Ang;
            n=2;
        break;
        case DISTANCIA: //DISTANCIA PC=>MBED 0xA3 PIDO DITANCIA; MBED =>PC UINT32_T DECUELCO DISTANCIA
            n=1;
        break;
        case TESTMOTORES:
            n=5;
            w.i8[0] = QInputDialog::getInt(this, "MOTOR 1(IZQ)", "%VEL",0,-100,100,5,&ok);
            buf[1]=w.i8[0];
            if(w.i8[0]<0)
                buf[2]=0;
            else
                buf[2]=1;

            w.i8[1] = QInputDialog::getInt(this, "MOTOR 2(DER)", "%VEL",0,-100,100,5,&ok);
            buf[3]=w.i8[1];
            if(w.i8[1]<0)
                buf[4]=0;
            else
                buf[4]=1;

        break;
        case NEGROIR:

            n=1;

            if(CONFIGIR){
                w.u8[0]=1;
                negro1 = QInputDialog::getInt(this, "VALOR(0-65535) NEGRO", "IR IZQUIERDO",0,0,65535,5,&ok);
                negro2 = QInputDialog::getInt(this, "VALOR(0-65535) NEGRO", "IR CENTRAL",0,0,65535,5,&ok);
                negro3 = QInputDialog::getInt(this, "VALOR(0-65535) NEGRO", "IR DERECHO",0,0,65535,5,&ok);
            }else
                w.u8[0]=0;
            buf[1]=0;
        break;
        case BLANCOIR:

            n=1;
            if(CONFIGIR){
                w.u8[0]=1;
                blanco1 = QInputDialog::getInt(this, "VALOR(0-65535) BLANCO", "IR IZQUIERDO",0,0,65535,5,&ok);
                blanco2 = QInputDialog::getInt(this, "VALOR(0-65535) BLANCO", "IR CENTRAL",0,0,65535,5,&ok);
                blanco3 = QInputDialog::getInt(this, "VALOR(0-65535) BLANCO", "IR DERECHO",0,0,65535,5,&ok);
            }else
                w.u8[0]=0;

        break;
        case PANEO:  //PANEO Pc=>MBED =0xA5 PASO PANEO ; MBED 0=> PC UINT32_T X18 DEVUELVO LAS DISTANCIAS
            BanRad=false;
            n=1;
        break;
    }

    if(n){
        buf[0] = cmd;
        SendCMD(buf, n);
    }
}


void QForm1::DecodeCmd(uint8_t *rxBuf){
    QString str;

    static uint8_t j=0;

    switch (rxBuf[0]) {
    case LEDS:
        str = "LED3: ";
        if(rxBuf[1] & 0x08)
            str = str + "OFF";
        else
            str = str + "ON";
        str = str + " - LED2: ";
        if(rxBuf[1] & 0x04)
            str = str + "OFF";
        else
            str = str + "ON";
        str = str + " - LED1: ";
        if(rxBuf[1] & 0x02)
            str = str + "OFF";
        else
            str = str + "ON";
        str = str + " - LED0: ";
        if(rxBuf[1] & 0x01)
            str = str + "OFF";
        else
            str = str + "ON";
        ui->plainTextEdit->appendPlainText(str);
        break;
     case PULSADORES:
            str = "SW3: ";
            if(rxBuf[1] & 0x08)
                str = str + "HIGH";
            else
                str = str + "LOW";
            str = str + " - SW2: ";
            if(rxBuf[1] & 0x04)
                str = str + "HIGH";
            else
                str = str + "LOW";
            str = str + " - SW1: ";
            if(rxBuf[1] & 0x02)
                str = str + "HIGH";
            else
                str = str + "LOW";
            str = str + " - SW0: ";
            if(rxBuf[1] & 0x01)
                str = str + "HIGH";
            else
                str = str + "LOW";
            ui->plainTextEdit->appendPlainText(str);
        break;

    case ALIVE:

        if(rxBuf[1] == ACKNOWLEDGE)
            ui->plainTextEdit->appendPlainText("I'M ALIVE");
        break;

    case SERVO:

        if(rxBuf[1] == ACKNOWLEDGE)
            ui->plainTextEdit->appendPlainText("MOVIENDO");
        else
        if(rxBuf[1] == SERVOSTOP)
            ui->plainTextEdit->appendPlainText("SERVO DETENIDO");
        break;

    case DISTANCIA:
        if(rxBuf[2]!=0){
            for(int i=0;i<4;i++)
                w.i8[i]=rxBuf[i+1];
            ui->Distance->setText((QString("Distancia medida(cM): %1").arg(w.u32/58.0, 2,'f', 10, QChar('0'))));
        }else
             ui->Distance->setText("FUERA DE RANGO");
        break;
    case PANEO:

            if(rxBuf[1] == ACKNOWLEDGE){
                 ui->plainTextEdit->appendPlainText("INICIANDO PANEO");
                 BanRad=false;
            }else
            for(int i=0;i<4;i++)
                w.i8[i]=rxBuf[i+1];
            ui->Distance->setText((QString("Distancia medida(cM): %1").arg(w.u32/58.0, 2,'f', 10, QChar('0'))));

            ActiveRadar((w.u32/58)*3,10*j);
            j++;

            if(j==19){
               j=0;
               BanRad=true;
            }
//            emit pasoPuntos(w.u32);
 //           pasoPuntos(w.u32);

        break;
        case NEGROIR:

            ui->plainTextEdit->appendPlainText("MIDIENDO IR");
            w2.u8[0]=rxBuf[1];
            w2.u8[1]=rxBuf[2];
            negro1=w2.u16;
            ui->N1->setText((QString("N1: %1").arg(negro1, 2, 10, QChar('0'))));

            w2.u8[0]=rxBuf[3];
            w2.u8[1]=rxBuf[4];
            negro2=w2.u16;
            ui->N2->setText((QString("N2: %1").arg(negro2, 2, 10, QChar('0'))));

            w2.u8[0]=rxBuf[5];
            w2.u8[1]=rxBuf[6];
            negro3=w2.u16;
            ui->N3->setText((QString("N3: %1").arg(negro3, 2, 10, QChar('0'))));

        break;
    case UNKNOWNCOMANND:

        ui->plainTextEdit->appendPlainText("NO CMD");
        break;
    }
}
void QForm1::DrawRadar(){

    QPen pen;
    QBrush brush;
    QPainter painter(QPaintBox1->getCanvas());
    uint32_t cen=0;

    cen = ui->ACTIVERADAR->height()/3;

    pen.setWidth(4);
    pen.setColor(Qt::darkGray);

    brush.setColor(Qt::darkGreen);
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawEllipse(QPointF(ui->ACTIVERADAR->width()/2,ui->ACTIVERADAR->height()),(ui->ACTIVERADAR->height()),ui->ACTIVERADAR->height());
    painter.setBrush(Qt::NoBrush);

    for(int i=1;i<3;i++)
         painter.drawEllipse(QPointF(ui->ACTIVERADAR->width()/2,ui->ACTIVERADAR->height()),(cen*i),cen*i);

}
void QForm1::ActiveRadar(uint32_t R,uint32_t tita){

   QPen pen;
   QPainter painter(QPaintBox1->getCanvas());
   float X=0,Y=0;

   X=R*cos((tita*M_PI)/180);
   Y=R*sin((tita*M_PI)/180);

   painter.translate(ui->ACTIVERADAR->width()/2, ui->ACTIVERADAR->height());

   pen.setWidth(10);
   pen.setColor(Qt::red);
   painter.setPen(pen);

   painter.drawEllipse(X,-Y,10,10);
   QPaintBox1->update();
}

void QForm1::ActiveLine(){

    static int32_t i=0;
    QPen pen;
    QPainter painter(QPaintBox1->getCanvas());

    painter.translate(ui->ACTIVERADAR->height(), ui->ACTIVERADAR->height());

    painter.rotate(i);

    if(i>180){
        i=0;
        painter.rotate(180);
    }
    i++;

    pen.setWidth(4);
    pen.setColor(Qt::gray);
    painter.setPen(pen);
    painter.drawLine(0,0,-ui->ACTIVERADAR->height(),0);

    QPaintBox1->update();
}
//void QForm1::pasoPuntos(uint32_t Puntosradar){
//    if(radar->isHidden())
//        radar->show();
//    else
//        radar->hide();

//}

void QForm1::on_DIRECT_clicked()
{
    if(!DirectOn){
       DirectOn=true;
        ui->DIRECT->setText("STOP DIRECTCOM");
    }else{
        DirectOn=false;
        ui->DIRECT->setText("DIRECTCOM");
    }
}

void QForm1::DirectComunication(){

    uint8_t buf[2],n=1;
    buf[0]=0xA3;

    SendCMD(buf,n);
}

void QForm1::on_IRCONFIG_clicked()
{
    if(!CONFIGIR){
        CONFIGIR=true;
        ui->IRCONFIG->setText("CONFIG IR");

    }
    else{
        CONFIGIR=false;
        ui->IRCONFIG->setText("LEER IR");
    }
}

