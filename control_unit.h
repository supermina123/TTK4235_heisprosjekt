#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H
#include "hardware.h"
#include "elevator.h"
#include "queue_handler.h"

/**
* @file 
* @brief A control unit controlling the elevator
*
*/

elevator_orders orders;
elevator_controller ctrl;

int next_in_queue;


/**
* @brief Decides what to do with the next 
* order at a given floor
* 
* @param orders
* @param state
*
*/

void decide_next_order_at_floor(elevator_orders *orders, elevator_controller *controller);


void decide_to_stop_at_floor(elevator_orders *orders, elevator_controller *controller);

/**
* @brief Drives the elevator in a direction
*
*/


void driving(elevator_orders *orders, elevator_controller *controller);



//HVA MED LYS???

#endif
