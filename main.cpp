#include "DigitalOut.h"
#include "InterfaceDigitalIn.h"
#include "LCD.h"
#include "PinNames.h"
#include "PinNamesTypes.h"
#include "mbed.h"
#include <cstdio>

DigitalOut in4(PC_9);
DigitalOut in3(PC_8);
DigitalOut in2(PC_6);
DigitalOut in1(PC_5);
DigitalOut led(PC_0);
DigitalIn taster(PC_11);
lcd mylcd;
int i = 0;
void clickTaster(){
    switch (i) {

    case 0:
      mylcd.clear();
      mylcd.cursorpos(0);
      mylcd.printf("Wodkashot");
      // printf("wodkashot");
        thread_sleep_for(100);
        i++;
      break;
    case 1:
      mylcd.cursorpos(0);
      mylcd.printf("Wodkashot2");
      thread_sleep_for(100);
      i++;
      break;
    case 2:
      mylcd.cursorpos(0);
      mylcd.printf("Wodkashot3");
      thread_sleep_for(100);
      i = 0;
      
      break;
      
    }

}
int main() {
  mylcd.clear();
  clickTaster();
  
  //taster.mode(PullDown);
  // input.mode(PullDown);
       // Dispalyobjekt erstellen (kann auch global deklariert werden)
  


  while (true) {
    if (taster==true) {
        clickTaster();
  }

  } // end while
} // end mai
