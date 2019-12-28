/*
 * leds.h
 *
 * Created: 15.11.2019 22:34:32
 *  Author: Nick
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#define CONTROL_LED PINC0
#define RED_LED PINC1
#define YELLOW_LED PINC2
#define GREEN_LED PINC3

#define LED_MASK ((1 << RED_LED) | (1 << YELLOW_LED) | (1 << GREEN_LED))

void initLed();
void setSignal(uint8_t light, uint8_t inv);
void controlLed();

#endif /* LEDS_H_ */