#ifndef _KEYCHECKLED_H_
#define _KEYCHECKLED_H_

#include <Arduino.h>
#include <map>
#include <string>
#include "Config.h"

class KeyCheckLED{

  public:
    KeyCheckLED();
    void begin();
    void setLED(uint8_t keyCode);

    const static uint8_t LED_OFF = 0;

  private:
    uint8_t nowKeyCode = 0;
    std::map<uint8_t, std::string> keyMap {
        {0x80, "KEY_LEFT_CTRL"},
        {0x81, "KEY_LEFT_SHIFT"},
        {0x82, "KEY_LEFT_ALT"},
        {0x83, "KEY_LEFT_GUI"},
        {0x84, "KEY_RIGHT_CTRL"},
        {0x85, "KEY_RIGHT_SHIFT"},
        {0x86, "KEY_RIGHT_ALT"},
        {0x87, "KEY_RIGHT_GUI"},
        {0xDA, "KEY_UP_ARROW"},
        {0xD9, "KEY_DOWN_ARROW"},
        {0xD8, "KEY_LEFT_ARROW"},
        {0xD7, "KEY_RIGHT_ARROW"},
        {0xB2, "KEY_BACKSPACE"},
        {0xB3, "KEY_TAB"},
        {0xB0, "KEY_RETURN"},
        {0xB1, "KEY_ESC"},
        {0xD1, "KEY_INSERT"},
        {0xD4, "KEY_DELETE"},
        {0xD3, "KEY_PAGE_UP"},
        {0xD6, "KEY_PAGE_DOWN"},
        {0xD2, "KEY_HOME"},
        {0xD5, "KEY_END"},
        {0xC1, "KEY_CAPS_LOCK"},
        {0xC2, "KEY_F1"},
        {0xC3, "KEY_F2"},
        {0xC4, "KEY_F3"},
        {0xC5, "KEY_F4"},
        {0xC6, "KEY_F5"},
        {0xC7, "KEY_F6"},
        {0xC8, "KEY_F7"},
        {0xC9, "KEY_F8"},
        {0xCA, "KEY_F9"},
        {0xCB, "KEY_F10"},
        {0xCC, "KEY_F11"},
        {0xCD, "KEY_F12"},
        {0xF0, "KEY_F13"},
        {0xF1, "KEY_F14"},
        {0xF2, "KEY_F15"},
        {0xF3, "KEY_F16"},
        {0xF4, "KEY_F17"},
        {0xF5, "KEY_F18"},
        {0xF6, "KEY_F19"},
        {0xF7, "KEY_F20"},
        {0xF8, "KEY_F21"},
        {0xF9, "KEY_F22"},
        {0xFA, "KEY_F23"},
        {0xFB, "KEY_F24"}
      };
};

#endif //_KEYCHECKLED_H_
