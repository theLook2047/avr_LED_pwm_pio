#include <Arduino.h>

#define LED_PORT PORTB

int increment = 1;

SIGNAL(TIMER2_COMPA_vect)
{
    if (OCR2A != 0xFF)
        LED_PORT &= ~(1 << PB7);

    if (OCR2A == 0)
        OCR2A = 1;
    else if (increment < 0 && OCR2A == 1)
        OCR2A = 0;
    else
        OCR2A += increment;

    if (OCR2A <= 0 || OCR2A >= 0xFF)
        increment *= -1;
}

SIGNAL(TIMER2_OVF_vect)
{
    LED_PORT |= 1 << PB7;
}