#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H
#include "hardware.h"

/**
* @file 
* @brief A control unit controlling the elevator
*
*/

/** 
* @brief Defines an enum of the possible 
* states the elevator can hold.
*
*/

typedef enum {INIT_STATE, 
              DRIVING_STATE, 
              STOP_AT_FLOOR_STATE, 
              EMERGENCY_STOP_STATE, 
              IDLE_STATE} elevator_state;


/**
* @brief Defines a struct containing an order
* table in the shape of a HARDWARE_NUMBER_OF_FLOORS*3 
* matrix, and a priority queue with 
* HARDWARE_NUMBER_OF_FLOORS entries.
*
**/

typedef struct {
    int order_table[HARDWARE_NUMBER_OF_FLOORS][3];
    int priority_queue[HARDWARE_NUMBER_OF_FLOORS];
}elevator_orders;

int floor_to_stop;
int next_in_queue;

/**
* @brief Decides what to do with the next 
* order at a given floor
* 
* @param orders
* @param state
*
*/

void decide_next_order_at_floor(elevator_orders *orders, elevator_state *state);

/**
* @brief Drives the elevator in a direction
*
*/


void driving(elevator_orders *orders, elevator_state *state);


/** 
* @brief The elevator is at a still, waiting
* for new orders to handle.
*
*/


void waiting_at_floor(elevator_orders *orders);


//HVA MED LYS???

#endif
