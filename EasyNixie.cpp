#include "EasyNixie.h"

EasyNixie::EasyNixie(uint8_t outputEnable,uint8_t shcp, uint8_t stcp, uint8_t dsin):
        outputEnable(outputEnable),
        shcp(shcp),
        stcp(stcp),
        dsin(dsin)
{
    pinMode(outputEnable, OUTPUT);  
    pinMode(shcp, OUTPUT);
    pinMode(stcp, OUTPUT);
    pinMode(dsin, OUTPUT);
}

void EasyNixie::SetNixie(uint8_t number,uint8_t color,bool voltage,bool comma,uint16_t dimming){
    #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)//AnalogWrite is supported for some platfroms and not supported for others(Esp32?), so if you want to used dimming in this platoforms you can implement it ourself
    analogWrite(outputEnable,dimming);
    #endif
    uint8_t secondShiftRegisterData=0b00011100;
    if(number==8)secondShiftRegisterData|=0b00000001;
    if(number==9)secondShiftRegisterData|=0b00000010;
    if(color==EASY_NIXIE_RED)secondShiftRegisterData&=0b11101111;
    if(color==EASY_NIXIE_GREEN)secondShiftRegisterData&=0b11110111;
	if(color==EASY_NIXIE_BLUE)secondShiftRegisterData&=0b11111011;
    if(color==EASY_NIXIE_WHITE)secondShiftRegisterData&=0b11100011;
    if(color==EASY_NIXIE_RuB)secondShiftRegisterData&=0b11101011;
    if(color==EASY_NIXIE_RuG)secondShiftRegisterData&=0b11100111;
    if(color==EASY_NIXIE_BuG)secondShiftRegisterData&=0b11110011;	
    if(voltage)secondShiftRegisterData|=0b00100000;
    if(comma)secondShiftRegisterData|=0b01000000;
    slowShiftOut(dsin, shcp, MSBFIRST, secondShiftRegisterData);
    if(number<8)slowShiftOut(dsin, shcp, MSBFIRST, (uint8_t)(1<<number));
    else slowShiftOut(dsin, shcp, MSBFIRST, 0);

}

void EasyNixie::slowShiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) {
    for (uint8_t i = 0; i < 8; i++) {
        if (bitOrder == LSBFIRST) {
            digitalWrite(dataPin, (val & (1 << i)) ? HIGH : LOW);
        } else {
            digitalWrite(dataPin, (val & (1 << (7 - i))) ? HIGH : LOW);
        }
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(1);  // Short delay for timing
        digitalWrite(clockPin, LOW);
        delayMicroseconds(1);  // Short delay for timing
    }
}

void EasyNixie::Latch(void){
    digitalWrite(stcp, LOW);
    delay(1);
    digitalWrite(stcp, HIGH);
}


