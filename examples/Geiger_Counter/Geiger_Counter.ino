#define OUT_EN          3   //connect Pin ArduinoUNO 3 to OUT_EN
#define SHCP            4   //connect Pin ArduinoUNO 4 to SHCP
#define STCP            6   //connect Pin ArduinoUNO 6 to STCP
#define DSIN            7   //connect Pin ArduinoUNO 7 to DSIN
// Connect Geiger output to pin 2

EasyNixie en(OUT_EN,SHCP, STCP, DSIN); //Initialisation 'en' protocole
uint16_t pulses=0;
void geiger_pulse(){ // Geiger pulse detected
  pulses++;
}

void setup() 
{
  Serial.begin(115200);
  attachInterrupt(0, geiger_pulse, FALLING); //define external interrupts 
}

void loop()                          //Writing 0-9 number Value
{         
    Serial.println(pulses);                   
    en.SetNixie(pulses,5,true,false);           //en.SetNixie(NixieNubmer , Color , ON/Off_Nixie);   Set color= 5= Purple
    en.Latch();                      //Send your set to EaseNixie 

    delay(100);                     //Wait 1,4sec  
}
