/*
 * timer.h
 *
 * Created: 15.11.2019 23:17:07
 *  Author: Nick
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define TIMER_0_ADDITIONAL_DIV 10
void initTimer(void(*callback)(void));

typedef struct _mediaTimer{
    uint16_t time;
    uint8_t id;
    uint8_t isComplite;
    uint8_t isActive;
}mediaTimer;

#define MAX_TIMER_QUEUE

mediaTimer timer_queue[MAX_TIMER_QUEUE];

#endif /* TIMER_H_ */