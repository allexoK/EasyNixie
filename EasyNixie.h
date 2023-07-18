#ifndef _EASY_NIXIE
#define _EASY_NIXIE
#include "Arduino.h"

#define EASY_NIXIE_BLUE 1
#define EASY_NIXIE_GREEN 2
#define EASY_NIXIE_RED 3
#define EASY_NIXIE_WHITE 4

class EasyNixie{
    uint8_t outputEnable;
    uint8_t shcp;
    uint8_t stcp;
    uint8_t dsin;
    public:
    EasyNixie(uint8_t outputEnable,uint8_t shcp, uint8_t stcp, uint8_t dsin);
    void shiftNumber(uint8_t number,uint8_t color,bool voltage=true);
    void latch(void);
};

#endif