/**
 * \file
 *
 * \brief User board configuration template
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef CONF_BOARD_H
#define CONF_BOARD_H

#define MY_LED    IOPORT_CREATE_PIN(PORTA, 5)
#define MY_BUTTON IOPORT_CREATE_PIN(PORTA, 6)

#endif // CONF_BOARD_H
