#include "EasyNixie.h"    //Nixie library

#define OUT_EN 3   //connect Pin ArduinoUNO 3 to OUT_EN
#define SHCP   2   //connect Pin ArduinoUNO 2 to SHCP
#define STCP   6   //connect Pin ArduinoUNO 6 to STCP
#define DSIN   7   //connect Pin ArduinoUNO 7 to DSIN

EasyNixie en(OUT_EN,SHCP, STCP, DSIN); //Initialisation 'en' protocole



void setup() 
{
  pinMode(A5, INPUT);     //set A5 as a sond
}
//Hz-7,V-5, W-0, A-1;  
void loop() 
{
    int v = ((float)analogRead(A5)/(float)1023)*(float)50;
    en.SetNixie(5,4,true);           
    en.SetNixie(v%10,4,true);    
    en.SetNixie(v/10,4,true);    
    en.Latch();      
    delay(100);  
}
