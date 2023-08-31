#ifndef CONFIG_H_
#define CONFIG_H_

//------------------------------
// ESP32-BLE-Keyboard
// https://github.com/T-vK/ESP32-BLE-Keyboard
//--------------------------------
#include <BleKeyboard.h>

#include <map>
#include <vector>

// デバイス名
#define DEVICE_NAME "8bit Keyboard"

#define STOCK_DELAY_TIME 50
#define PUSH_DELAY_TIME 50

// LED設定
#define LED_KEY_VALID 12  //キーが有効かどうか

#define STOCK_MAX_NUM   3   // キーストックの最大数
#define LED_STOCK_01    13  // キーストック１つ目
#define LED_STOCK_03    23  // キーストック２つ目
#define LED_STOCK_02    22   // キーストック３つ目

const uint8_t LED_STOCK_LIST[] = {
  LED_STOCK_01,
  LED_STOCK_02,
  LED_STOCK_03
};

// ロックキー
#define LOCK_KEY      26      // キーロック用ボタン

// 制御ボタン
#define PUSH_BUTTON   27   // キー送信用ボタン
#define STOCK_BUTTON  14  // キーストック用ボタン

// キービット情報
#define KEY_BIT_NUM  8  // KEYBITの情報

#define KEY_BIT_01 19   // 文字コード 1bit目
#define KEY_BIT_02 18   // 文字コード 2bit目
#define KEY_BIT_03 5    // 文字コード 3bit目
#define KEY_BIT_04 17   // 文字コード 4bit目
#define KEY_BIT_05 16   // 文字コード 5bit目
#define KEY_BIT_06 4    // 文字コード 6bit目
#define KEY_BIT_07 2    // 文字コード 7bit目
#define KEY_BIT_08 15    // 文字コード 8bit目

const uint8_t KEYBIT_LIST[] = {
  KEY_BIT_01,
  KEY_BIT_02,
  KEY_BIT_03,
  KEY_BIT_04,
  KEY_BIT_05,
  KEY_BIT_06,
  KEY_BIT_07,
  KEY_BIT_08
};

//有効なキー情報
const std::map<uint8_t, std::string> KEY_MAP{
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
  {0xFB, "KEY_F24"},
  {0x20, "KEY_KEY_SPACE"},
  {0x21, "KEY_!"},
  {0x22, "KEY_"""},
  {0x23, "KEY_#"},
  {0x24, "KEY_$"},
  {0x25, "KEY_%"},
  {0x26, "KEY_&"},
  {0x27, "KEY_'"},
  {0x28, "KEY_("},
  {0x29, "KEY_)"},
  {0x2a, "KEY_*"},
  {0x2b, "KEY_+"},
  {0x2c, "KEY_."},
  {0x2d, "KEY_-"},
  {0x2e, "KEY_."},
  {0x2f, "KEY_/"},
  {0x30, "KEY_0"},
  {0x31, "KEY_1"},
  {0x32, "KEY_2"},
  {0x33, "KEY_3"},
  {0x34, "KEY_4"},
  {0x35, "KEY_5"},
  {0x36, "KEY_6"},
  {0x37, "KEY_7"},
  {0x38, "KEY_8"},
  {0x39, "KEY_9"},
  {0x3a, "KEY_:"},
  {0x3b, "KEY_;"},
  {0x3c, "KEY_<"},
  {0x3d, "KEY_="},
  {0x3e, "KEY_>"},
  {0x3f, "KEY_?"},
  {0x40, "KEY_@"},
  {0x41, "KEY_A"},
  {0x42, "KEY_B"},
  {0x43, "KEY_C"},
  {0x44, "KEY_D"},
  {0x45, "KEY_E"},
  {0x46, "KEY_F"},
  {0x47, "KEY_G"},
  {0x48, "KEY_H"},
  {0x49, "KEY_I"},
  {0x4a, "KEY_J"},
  {0x4b, "KEY_K"},
  {0x4c, "KEY_L"},
  {0x4d, "KEY_M"},
  {0x4e, "KEY_N"},
  {0x4f, "KEY_O"},
  {0x50, "KEY_P"},
  {0x51, "KEY_Q"},
  {0x52, "KEY_E"},
  {0x53, "KEY_S"},
  {0x54, "KEY_T"},
  {0x55, "KEY_U"},
  {0x56, "KEY_V"},
  {0x57, "KEY_W"},
  {0x58, "KEY_X"},
  {0x59, "KEY_Y"},
  {0x5a, "KEY_Z"},
  {0x5b, "KEY_["},
  {0x5c, "KEY_¥¥"},
  {0x5d, "KEY_]"},
  {0x5e, "KEY_^"},
  {0x5f, "KEY__"},
  {0x60, "KEY_`"},
  {0x61, "KEY_a"},
  {0x62, "KEY_b"},
  {0x63, "KEY_c"},
  {0x64, "KEY_d"},
  {0x65, "KEY_e"},
  {0x66, "KEY_f"},
  {0x67, "KEY_g"},
  {0x68, "KEY_h"},
  {0x69, "KEY_i"},
  {0x6a, "KEY_j"},
  {0x6b, "KEY_k"},
  {0x6c, "KEY_l"},
  {0x6d, "KEY_m"},
  {0x6e, "KEY_n"},
  {0x6f, "KEY_o"},
  {0x70, "KEY_p"},
  {0x71, "KEY_q"},
  {0x72, "KEY_r"},
  {0x73, "KEY_s"},
  {0x74, "KEY_t"},
  {0x75, "KEY_u"},
  {0x76, "KEY_v"},
  {0x77, "KEY_w"},
  {0x78, "KEY_x"},
  {0x79, "KEY_y"},
  {0x7a, "KEY_z"},
  {0x7b, "KEY_{"},
  {0x7c, "KEY_|"},
  {0x7d, "KEY_}"}
};

// キーStock情報
std::vector<uint8_t> stockKey;

bool pushButtonState = false;
bool stockButtonState = false;
bool keyLockState = false;
bool vaildState = false;
long stockDelay = 0;
long pushDelay = 0;
uint8_t push_key = 0;

BleKeyboard bleKeyboard(DEVICE_NAME);

#endif // CONFIG_H_
