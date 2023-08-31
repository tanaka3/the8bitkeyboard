#ifndef _STOCKLED_H_
#define _STOCKLED_H_

#include <Arduino.h>
#include <vector>
#include "Config.h"

class StockLED{

  public:
    StockLED();
    void begin();
    void setLED(uint8_t num);

    const static uint8_t LED_OFF = 0;

  private:
    uint8_t nowLED = -1;
    std::vector<uint8_t> stockLEDs { LED_STOCK_01, LED_STOCK_02, LED_STOCK_03 };
};

#endif //_STOCKLED_H_
