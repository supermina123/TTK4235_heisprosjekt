
#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "door.h"


typedef struct {INIT_STATE, 
                DRIVING_STATE, 
                STOP_AT_FLOOR_STATE, 
                EMERGENCY_STOP_STATE, 
                IDLE_STATE} states;



int orders[HARDWARE_NUMBER_OF_FLOORS][3];

int priority_queue[HARDWARE_NUMBER_OF_FLOORS] = {-1};






