#include "EasyNixie.h"    //Nixie library

#define OUT_EN 3   //connect Pin ArduinoUNO 3 to OUT_EN
#define SHCP   2   //connect Pin ArduinoUNO 2 to SHCP
#define STCP   6   //connect Pin ArduinoUNO 6 to STCP
#define DSIN   7   //connect Pin ArduinoUNO 7 to DSIN 
EasyNixie en(OUT_EN,SHCP, STCP, DSIN); //Initialisation 'en' protocole

void setup() 
{
  Serial.begin(115200);
}
void loop()                          //Writing 0-7 color Value
{
  for (uint8_t j = 0; j <= 7; j++)      
  {                                  
    en.SetNixie(0,j,false);          //en.SetNixie(NixieNubmer , Color , ON/Off_Nixie);
    en.Latch();                      //Send your set to EaseNixie 

    Serial.print("'j' is equal: ");  //Print to COM actual Value
    Serial.println(j);               //Print to COM actual Value 
    delay(1200);                     //Stop program for 1,2[sec] 
  }  
}
