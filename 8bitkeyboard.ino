#include "config.h"

void setup() {
  Serial.begin(115200);

  Serial.println("Starting Bluetooth keyboard!");
  bleKeyboard.begin();


  // キースイッチの初期化
  for(uint8_t i=0; i<KEY_BIT_NUM; i++){
    pinMode(KEYBIT_LIST[i], INPUT_PULLDOWN);
  }

  // ロックボタンの初期化
  pinMode(LOCK_KEY, INPUT_PULLDOWN);

  // 制御ボタンの初期化
  pinMode(PUSH_BUTTON, INPUT_PULLDOWN);
  pinMode(STOCK_BUTTON, INPUT_PULLDOWN);

  // LEDの初期化
  for(uint8_t i=0; i<STOCK_MAX_NUM; i++){  
    pinMode(LED_STOCK_LIST[i], OUTPUT);
  }
  
  pinMode(LED_KEY_VALID, OUTPUT);

  showStockLED();
}



void loop() {

  /*
  Serial.print("code:");
  
  Serial.print(digitalRead(LOCK_KEY));
  Serial.print(", ");
  Serial.print(digitalRead(PUSH_BUTTON));
  Serial.print(", ");
  Serial.print(digitalRead(STOCK_BUTTON));
  
  Serial.print(" | ");
  */
  
  /*
  for(int i=0;i<95; i++){!
    Serial.println(test[i], HEX); 
    bleKeyboard.press(0x85);
    bleKeyboard.press(test[i]);
    bleKeyboard.releaseAll();
    delay(1000);
  }
  */

  // BLキーボードして接続されていない場合は処理を行わない
  if (!bleKeyboard.isConnected()) {
    delay(10);
    return;
  }
    
  uint16_t code = GetKeyCode();
  showValidLED(code);
  //Serial.println(code);
  
  // 送信ボタンが押された場合
  if(digitalRead(PUSH_BUTTON) &&  !pushButtonState  && (millis() - pushDelay > PUSH_DELAY_TIME)){
    Serial.print("PUSH_BUTTON:");
    for(uint8_t i=0; i<KEY_BIT_NUM; i++){
      Serial.print(digitalRead(KEYBIT_LIST[i]));
      Serial.print(" (");
      Serial.print(KEYBIT_LIST[i]);
      Serial.print(") : ");
    }
    Serial.println(code); 
    push_key = code;            
    //Serial.println(code);
    pushButtonState = true;
    
    // キーロックがない場合は、キーストックを削除する
    if(!digitalRead(LOCK_KEY)){

      // ストックキーも送信する
      for (auto key: stockKey){
        Serial.println(key);
        bleKeyboard.press(key);  
      }
          
      stockKey.clear();
      showStockLED();
    }
    
    // 現在の入力を送信する
    bleKeyboard.press(code);    
  }

  // 送信ボタンが離された場合
  if(!digitalRead(PUSH_BUTTON) && pushButtonState){
    pushButtonState = false;
    pushDelay = millis();
    if(digitalRead(LOCK_KEY)){
      bleKeyboard.release(push_key);
    }
    else{
      bleKeyboard.releaseAll();
    }
  }
  
  //ロックしてない場合のみストックが可能とする
  if(digitalRead(LOCK_KEY) && keyLockState == false){
    Serial.println("KEY_LOCK:");
    keyLockState = true;
    // ストックキーも送信する
    for (auto key: stockKey){
      Serial.println(key);      
      bleKeyboard.press(key);  
    }    
  }
  if(!digitalRead(LOCK_KEY)){
    if(keyLockState){
      keyLockState = false;
      for (auto key: stockKey){
        bleKeyboard.release(key);  
      }
      stockKey.clear();
      showStockLED();       
    }
    
    // ストックキーが押された場合
    if(digitalRead(STOCK_BUTTON) &&  !stockButtonState && (millis() - stockDelay > STOCK_DELAY_TIME) ){
      Serial.println("STOCK_BUTTON");

      stockButtonState = true;
  
      if(stockKey.size() <STOCK_MAX_NUM){
        //キーをストックする
        stockKey.push_back(code);
        showStockLED(); 
      }
    }

    // ストックキーが離された場合
    if(!digitalRead(STOCK_BUTTON) &&  stockButtonState){
      Serial.println("STOCK_BUTTON_UP");
      stockButtonState = false;
      stockDelay = millis();
    }
    
  }
}

uint8_t GetKeyCode(){
  
  int keyCode = 0;
  for(uint8_t i=0; i<KEY_BIT_NUM; i++){
    /*
    Serial.print(digitalRead(KEYBIT_LIST[i]));
    Serial.print(" (");
    Serial.print(KEYBIT_LIST[i]);
    Serial.print("), ");*/
        
    keyCode += digitalRead(KEYBIT_LIST[i]) << i;
  }

  return keyCode;
}


void showValidLED(uint8_t code){
  
  if(KEY_MAP.count(code) > 0 && !vaildState){
    vaildState = true;
    digitalWrite(LED_KEY_VALID, HIGH);
  }

  if(KEY_MAP.count(code) == 0 && vaildState){
    vaildState = false;
    digitalWrite(LED_KEY_VALID, LOW);
  }
}

void showStockLED(){
  
  int stock_size = stockKey.size();
  Serial.print("stock_size:");
  Serial.println(stock_size);
 
  
  for(uint8_t i=0; i<STOCK_MAX_NUM; i++){
    digitalWrite(LED_STOCK_LIST[i],  i < stock_size ? HIGH : LOW); 
  }
}
