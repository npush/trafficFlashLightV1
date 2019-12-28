/*
 * leds.c
 *
 * Created: 15.11.2019 21:48:11
 *  Author: Nick
 */ 
#include <avr/io.h>
#include <stdint.h>
#include "states.h"
#include "leds.h"


void initLed()
{
    DDRC = (1 << RED_LED) | (1 << YELLOW_LED) | (1 << GREEN_LED);
}

void setSignal(uint8_t light, uint8_t inv)
{
    //uint8_t a = PORTC;
    if (inv) {
        PORTC &= light;
        PORTC ^= light;
    } else {
        PORTC &= light;
        PORTC = light;// ((a & LED_MASK) ^ (1 << light)) & (1 << light);
    }    
}

void controlLed()
{
    PORTC ^= (1 << CONTROL_LED);
}