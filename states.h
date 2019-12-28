/*
 * states.h
 *
 * Created: 15.11.2019 20:40:57
 *  Author: Nick
 */ 


#ifndef STATES_H_
#define STATES_H_

typedef struct _state{
    uint8_t switchSignal;
    uint8_t flashLight;
    uint8_t timeStayIn;
    uint8_t isFlash;
    void (*routine)(int signal, struct _state *currentState);
    struct _state *nextState;
    const char currentStateName[15];
}state;

#define STATE_SIZE sizeof(state)

enum flashModes {
    initial_state,
    red_state,
    yellow_state,
    green_state,
    flash_green_state,
    red_yellow_state
};

enum flashColorLights {
    RED = 2, YELLOW = 4, GREEN = 8
};

void initial(int signal, struct _state *currentState);
void red(int signal, struct _state *currentState);
void yellow(int signal, struct _state *currentState);
void green(int signal, struct _state *currentState);
void flash_green(int signal, struct _state *currentState);
void A(int signal, struct _state *currentState);



#endif /* STATES_H_ */