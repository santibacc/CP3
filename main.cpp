#include "mbed.h"
DigitalOut LED(PC_13);
Timer myTimer;

int main(){

    myTimer.start();
    uint32_t intervalo=100,counter=0;
    uint32_t mask=  0xA8000000;
    uint32_t move; 
    while(1){
        
        if((myTimer.read_ms()-counter)>intervalo){
            counter=myTimer.read_ms();
            
            if(mask<<move == 1){
                LED=0;
                move++;
            }else{
                LED=1;
                move++;
            }
        }
    }
}