#include "mbed.h"
#define TITI 100
#define WAIT 1500
DigitalOut LED(PC_13);
Timer myTimer;

int main(){

    myTimer.start();
    uint32_t counter=0;
    uint32_t intervalo,count=0;
    intervalo=TITI;

    while(1){
        
        if((myTimer.read_ms()-counter)>intervalo){
            counter=myTimer.read_ms();
            
            count++;
            if(count<6){
                LED=!LED;
            }else
                LED=1;
            if(count>19)
                count=0;
        }
    }
}