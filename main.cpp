#include "mbed.h"

DigitalOut LED(PC_13);

int main(){

    while(1){
    	LED = !LED;
    	wait_ms(500);
    }
}