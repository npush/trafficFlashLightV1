/*
 * states.c
 *
 * Created: 15.11.2019 20:39:51
 *  Author: Nick
 */ 

#include <avr/pgmspace.h>
#include "states.h"
#include "leds.h"


void initial(int signal, struct _state *currentState)
{
    setSignal(currentState->flashLight, currentState->isFlash);
    if (currentState->timeStayIn-- == 0) {
        memcpy_P(currentState, currentState->nextState, STATE_SIZE);
    }
}
void A(int signal, struct _state *currentState)
{
    setSignal(currentState->flashLight, currentState->isFlash);
    if (currentState->timeStayIn-- == 0) {
        memcpy_P(currentState, currentState->nextState, STATE_SIZE);
    }
}
