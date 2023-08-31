#include "BitSwitch.h"

BitSwitch::BitSwitch()
{
}

/**
 * init
 */
void BitSwitch::begin(){

  for (auto siwtch: bitSwitches){
    siwtch->begin();  
  }

}

/**
 * bit => keyboard code
 */
uint8_t BitSwitch::key(){
  uint8_t keyCode = 0;
  
  for(uint8_t i=0; i<bitSwitches.size(); i++){
    keyCode += bitSwitches[i]->read() << i;
  }

  return keyCode;
}
