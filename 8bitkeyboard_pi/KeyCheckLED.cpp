#include "KeyCheckLED.h"

KeyCheckLED::KeyCheckLED(){
}

void KeyCheckLED::begin(){
  pinMode(LED_KEY_CHECK, OUTPUT);
}

void KeyCheckLED::setLED(uint8_t keyCode){

  if(nowKeyCode == keyCode){
    return;
  }

  if( keyCode > 0 && keyCode < 0x80){
    digitalWrite(LED_KEY_CHECK, HIGH); 
  }
  else{
    digitalWrite(LED_KEY_CHECK, keyMap.count(keyCode) == 0 ? LOW : HIGH); 
  }

  nowKeyCode = keyCode;
  
}
