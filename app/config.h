#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <Arduino.h>

/* 
 *****************************************
  ATtiny 1604
     VCC        | 1      14 | GND
TA1  SS  D0 PA4 | 2      13 | PA3 D10 SCK SYNC-B
TA2      D1 PA5 | 3      12 | PA2 D9 MISO SYNC-A
TB1      D2 PA6 | 4      11 | PA1 D8 MOSI LED_BEAT
TB2      D3 PA7 | 5      10 | UPDI
MIN  RXD D4 PB3 | 6       9 | PB0 D7 SCL
     TXD D5 PB2 | 7       8 | PB1 D6 SDA
 *****************************************
*/
#define LED_BEAT  8
#define OUT_SYNCA 9
#define OUT_SYNCB 10
#define SW_TA1    0
#define SW_TA2    1
#define SW_TB1    2
#define SW_TB2    3

#endif