#include "StockLED.h"

StockLED::StockLED(){
}

void StockLED::begin(){
  for (auto led: stockLEDs){
    pinMode(led, OUTPUT);
  }
}


void StockLED::setLED(uint8_t stock_size){
  
  if(nowLED == stock_size){
    return;
  }

  if(stock_size < 0 || stock_size > stockLEDs.size()){
    return;
  }

  for(uint8_t i=0; i<stockLEDs.size(); i++){
    digitalWrite(stockLEDs[i],  i < stock_size ? HIGH : LOW); 
  }

  nowLED = stock_size;
}
