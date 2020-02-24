#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H
#include "hardware.h"


typedef enum {INIT_STATE, 
                DRIVING_STATE, 
                STOP_AT_FLOOR_STATE, 
                EMERGENCY_STOP_STATE, 
                IDLE_STATE} elevator_state;


typedef struct {
    int order_table[HARDWARE_NUMBER_OF_FLOORS][3];
    int priority_queue[HARDWARE_NUMBER_OF_FLOORS];
}elevator_orders;

int floor_to_stop;
int next_in_queue;

void decide_next_order_at_floor(elevator_orders *orders, elevator_state *state);

void driving(elevator_orders *orders, elevator_state *state);

void waiting_at_floor(elevator_orders *orders);


//HVA MED LYS???

#endif