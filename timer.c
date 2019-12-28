/*
 * timer.c
 *
 * Created: 15.11.2019 20:57:28
 *  Author: Nick
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "timer.h"
#include "leds.h"


uint8_t timerDiv;

void (*_callback)(void);

void initTimer(void (*callback)(void))
{
    _callback = callback;
    timerDiv = TIMER_0_ADDITIONAL_DIV;
    TCCR0 = (1 << CS02) | (1 << CS00);
    TIMSK = (1 << TOIE0);
}


ISR (TIMER0_OVF_vect)
{
    TIFR = (1 << TOV0);
    controlLed();
    if (timerDiv) {
        timerDiv--;
        return;
    }
    timerDiv = TIMER_0_ADDITIONAL_DIV;
    _callback();
    // call routine
}