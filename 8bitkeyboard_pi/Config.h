#ifndef _CONFIG_H_
#define _CONFIG_H_

#define DEBUG

// Stock LED GPIO
#define LED_STOCK_01    1   // stcok led1
#define LED_STOCK_03    2   // stcok led2
#define LED_STOCK_02    3   // stcok led3

#define STOCK_MAX_NUM   3   // Max stock num

// Key check LED GPIO
#define LED_KEY_CHECK   4   // character validate led

// Lock key GPIO
#define SWITCH_LOCK     5   // lock key button

// Push button GPIO
#define PUSH_BUTTON     6   // send key
#define STOCK_BUTTON    7   // stock key

// Bit switch GPIO
#define SWITCH_BIT_01   8   // character 1bit
#define SWITCH_BIT_02   9   // character 2bit
#define SWITCH_BIT_03   10  // character 3bit
#define SWITCH_BIT_04   11  // character 4bit
#define SWITCH_BIT_05   12  // character 5bit
#define SWITCH_BIT_06   13  // character 6bit
#define SWITCH_BIT_07   14  // character 7bit
#define SWITCH_BIT_08   15  // character 8bit

#endif  /* _CONFIG */
