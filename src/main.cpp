#include <Arduino.h>

#define LED_DDR DDRB

//void setup() {
//  LED_DDR=1<<PB5;
//
//  TCCR2A=0;
//  TCCR2B=1<<CS22;      //64분주
//  TCNT2=231;           //25만큼 count할때마다 TIFR=1
//  TIMSK2=1<<TOIE2;   //100micros 마다 INT가 발생
//}
//

/***********이하는 fast PWM mode ****************/

void setup()
{
  //Serial.begin(9600);

  LED_DDR = 1 << DDB7;

  TCCR2A = TCCR2B = 0;
  TCCR2A = 1 << WGM21 | 1 << WGM20;           //FAST PWM모드
  TCCR2B = 1 << CS22 | 1 << CS21 | 1 << CS20; //1024분주 : 64=16M/preS=2^(x-4)us (현재 x=10)
  TCNT2 = OCR2A = 0;
  TIMSK2 = 1 << OCIE2A | 1 << TOIE2;
}

void loop() {}