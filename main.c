/*
 * fashLight.c
 *
 * Created: 15.11.2019 20:15:51
 * Author : Nick
 */ 

/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "src/asf.h"
#include "main.h"
#include "states.h"
#include "timer.h"
#include "leds.h"

const state PROGMEM FlashStates[] =  {
    /*initial_state*/{1, YELLOW, 5, 1, &initial, &FlashStates[red_state], "initial"},
    /*red_state*/{1, RED, 5, 0, &A, &FlashStates[red_yellow_state], "red"},
    /*yellow_state*/{1, YELLOW, 2, 0, &A, &FlashStates[red_state], "yellow"},
    /*green_state*/{1, GREEN, 10, 0, &A, &FlashStates[flash_green_state], "green"},
    /*flash_green_state*/{1, GREEN, 4, 1, &A, &FlashStates[yellow_state], "flash green"},
    /*red_yellow_state*/{1, RED | YELLOW, 2, 0, &A, &FlashStates[green_state], "red + yellow"}
};

state FlashlightState;

void call()
{
    FlashlightState.routine(1, &FlashlightState);
}

int main(void)
{
 	/* Insert system clock initialization code here (sysclk_init()). */

 	board_init();

 	/* Insert application code here, after the board has been initialized. */
        
    memcpy_P(&FlashlightState, &FlashStates[initial_state], STATE_SIZE);

    initTimer(&call);
    initLed();
    sei();
    
    /* Replace with your application code */
    while (1) 
    {
        
    }
}
