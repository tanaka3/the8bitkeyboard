#ifndef _BITSWITCH_H_
#define _BITSWITCH_H_

#include <Arduino.h>
#include "Config.h"
#include "Button.h"

#include <map>
#include <vector>

/**
 * @brief 
 * 
 */
class BitSwitch{

  public:
    BitSwitch();
    void begin();
    uint8_t key();

  private:
    Button bit1Switch = Button(SWITCH_BIT_01);
    Button bit2Switch = Button(SWITCH_BIT_02);
    Button bit3Switch = Button(SWITCH_BIT_03);
    Button bit4Switch = Button(SWITCH_BIT_04);
    Button bit5Switch = Button(SWITCH_BIT_05);
    Button bit6Switch = Button(SWITCH_BIT_06);
    Button bit7Switch = Button(SWITCH_BIT_07);
    Button bit8Switch = Button(SWITCH_BIT_08);
    
    std::vector<Button *> bitSwitches {
      &bit1Switch,
      &bit2Switch,
      &bit3Switch,
      &bit4Switch,
      &bit5Switch,
      &bit6Switch,
      &bit7Switch,
      &bit8Switch      
    };
};

#endif //_BITSWITCH_H_
