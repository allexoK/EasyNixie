#include "EasyNixie.h"

#define OUT_EN 3   //connect Pin ArduinoUNO 3 to OUT_EN
#define SHCP   2   //connect Pin ArduinoUNO 2 to SHCP
#define STCP   6   //connect Pin ArduinoUNO 6 to STCP
#define DSIN   7   //connect Pin ArduinoUNO 7 to DSIN

EasyNixie en(OUT_EN,SHCP, STCP, DSIN); //Initialisation 'en' protocole

void setup() 
{
  Serial.begin(115200);
}
void loop()                          //Writing 0-9 number Value
{
  for (uint8_t i = 0; i <= 9; i++)      
  {                                  
    en.SetNixie(i,i,true,true,0);    //en.SetNixie(NixieNubmer , Color , ON/Off_Nixie);   Set color= 5= Purple; dimming=0 - max brightness
    en.Latch();                      //Send your set to EaseNixie 

    Serial.print("'i' is equal: ");  //Print to COM actual Value
    Serial.println(i);
    delay(100);                     //Wait 1,4sec  
  }  
  
}
