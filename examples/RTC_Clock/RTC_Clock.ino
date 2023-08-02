/*
EasyNixie Clock
1)Example for 4 nixie lamp 
2)Just change 'Time' value for the current time
3.) using DS1302 Clock module
*/

#include <virtuabotixRTC.h>  //RTC Library                                                                            
#include "EasyNixie.h"       //Nixie library
#define OUT_EN 3   //connect Pin ArduinoUNO 3 to OUT_EN
#define SHCP   2   //connect Pin ArduinoUNO 2 to SHCP
#define STCP   6   //connect Pin ArduinoUNO 6 to STCP
#define DSIN   7   //connect Pin ArduinoUNO 7 to DSIN
EasyNixie en(OUT_EN,SHCP, STCP, DSIN); //Initialisation 'en' protocole

virtuabotixRTC myRTC(8, 9, 10);   //(pin 8 to CLK, pin 9 to DAT, pin 10 to RST)
 

void setup() 
{
// seconds, minutes, hours, day of the week, day of the month, month, year
    myRTC.setDS1302Time(00, 37, 21, 2, 1, 8, 2023);
}
void loop()                        
{    
    myRTC.updateTime();
    int a = myRTC.minutes%10;
    int b = myRTC.minutes/10;
    int c = myRTC.hours%10;
    int d = myRTC.hours/10;    
    en.SetNixie(a,5,true);           //en.SetNixie Last number 
    en.SetNixie(b,5,true);           //en.SetNixie Minute 
    en.SetNixie(c,5,true);           //en.SetNixie Hour
    en.SetNixie(d,5,true);           //en.SetNixie First Number 
    en.Latch();                      //Send your set to EaseNixie 
  delay(1000);                       //Wait a second 
}
