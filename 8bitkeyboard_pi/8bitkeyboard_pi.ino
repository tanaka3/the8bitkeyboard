#include <Arduino.h>
#include <Keyboard.h>
#include <vector>
#include "Config.h"
#include "BitSwitch.h"
#include "StockLED.h"
#include "KeyCheckLED.h"
#include "Button.h"

BitSwitch  bitSwitch;
StockLED stockLED;
KeyCheckLED keyCheckLED;

Button pushButton(PUSH_BUTTON);
Button stockButton(STOCK_BUTTON);
Button switchLock(SWITCH_LOCK);

std::vector<uint8_t> stockKey;
uint8_t pushKey = 0;

void setup() {

  Serial.begin(115200);

  Keyboard.begin();
  
  stockLED.begin();
  keyCheckLED.begin();
  
  bitSwitch.begin();
  pushButton.begin();
  stockButton.begin();
  switchLock.begin();

  stockLED.setLED(StockLED::LED_OFF);
  keyCheckLED.setLED(KeyCheckLED::LED_OFF);
}

void loop() {

  uint8_t keyCode = bitSwitch.key();
  
  //key press
  if(pushButton.pressed()){

    pushKey = keyCode;
    
    if(!switchLock.read()){
      for (auto key: stockKey){
        Serial.print("stock in:");        
        Serial.println(key);
        Keyboard.press(key);  
      }
      stockKey.clear();         
    }
    
    Serial.print("in:"); 
    Serial.println(pushKey);
    Keyboard.press(pushKey);
  }

  // key release
  if(pushButton.released()){
    Serial.println("release");
    if(switchLock.read()){
      Keyboard.release(pushKey);
    }
    else{
      Keyboard.releaseAll();
    }
  }

  // key press (lock)
  if(switchLock.pressed()){
    
      for (auto key: stockKey){
        Keyboard.press(key);  
      }
  }

  // key stock
  if(switchLock.released()){
    
    for (auto key: stockKey){
      Keyboard.release(key);  
    }
    stockKey.clear();   
  }

  if(!switchLock.read()){    

    // add key stock.
    if(stockButton.pressed()){
      if(stockKey.size() < STOCK_MAX_NUM){
        Serial.print("stock:");
        Serial.println(keyCode);
        stockKey.push_back(keyCode);
      }
    }
  }

  // led control
  stockLED.setLED(stockKey.size());
  keyCheckLED.setLED(keyCode);

}
