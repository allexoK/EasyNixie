#ifndef _EASY_NIXIE
#define _EASY_NIXIE
#include "Arduino.h"

#define EASY_NIXIE_BLUE 1
#define EASY_NIXIE_GREEN 2
#define EASY_NIXIE_RED 3
#define EASY_NIXIE_WHITE 4
#define EASY_NIXIE_RuB 5
#define EASY_NIXIE_RuG 6
#define EASY_NIXIE_BuG 7

class EasyNixie{
    uint8_t outputEnable;
    uint8_t shcp;
    uint8_t stcp;
    uint8_t dsin;
    public:
    EasyNixie(uint8_t outputEnable,uint8_t shcp, uint8_t stcp, uint8_t dsin);
    void SetNixie(uint8_t number,uint8_t color,bool voltage=true,bool comma = false);
    void Latch(void);
};

#endif

