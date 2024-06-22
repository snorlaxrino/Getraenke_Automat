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
DigitalIn tasterMenu(PC_11);
DigitalIn tasterSelected(PC_10);
lcd mylcd;
int menuNumber = 0;
int drinkSelected = 0;
void clickTasterMenu() {
  switch (menuNumber) {

  case 0:
    mylcd.clear();
    mylcd.cursorpos(0);
    mylcd.printf("Wodkashot");
    // printf("wodkashot");
    thread_sleep_for(100);
    menuNumber++;
    drinkSelected = 0;
    break;
  case 1:
    mylcd.cursorpos(0);
    mylcd.printf("Wodkashot2");
    thread_sleep_for(100);
    menuNumber++;
    drinkSelected = 1;
    break;
  case 2:
    mylcd.cursorpos(0);
    mylcd.printf("Wodkashot3");
    thread_sleep_for(100);
    menuNumber = 0;
    drinkSelected = 2;
    break;
  }
}
void clickSelected(){
    if (drinkSelected==0) {
        in1 = 0; // forward out 1 & 2
        in2 = 1; // forward in1=0 in2=1 out 1 & 2
        thread_sleep_for(10000);
        in1 = 0; // forward out 1 & 2
        in2 = 0; // forward in1=0 in2=1 out 1 & 2
        printf("motor1 rennt: %d\n ",drinkSelected);
    }
    if (drinkSelected==1) {
        in3 = 1;
        in4 = 0;
        thread_sleep_for(90000);
        in3 = 0;
        in4 = 0;
        printf("motor2 rennt: %d\n",drinkSelected);
    }
    if (drinkSelected==2) {
        in1 = 0; // forward out 1 & 2
        in2 = 1;
        thread_sleep_for(10000);
        in1 = 0; // forward out 1 & 2
        in2 = 0;

        in3 = 1;
        in4 = 0;
        thread_sleep_for(80000);
        in3 = 0;
        in4 = 0;
        printf("beide rennt %d\n",drinkSelected);
    }
    thread_sleep_for(500);
}
int main() {
  tasterSelected.mode(PullDown);
  tasterMenu.mode(PullDown);
  printf("Int i= %d\n",menuNumber);
  mylcd.clear();
  mylcd.printf("click button");
  //clickTasterMenu();
  
  while (true) {
    if (tasterMenu==true) {
        printf("auswahl\n");
        printf("Int i= %d\n",menuNumber);
        clickTasterMenu();
  }
    if (tasterSelected==true) {
        printf("motor laufen\n");
        printf("Int i= %d\n",menuNumber);
        clickSelected();
    }
    else {
    //printf("idle\n");
    }

  } // end while
} // end mai
