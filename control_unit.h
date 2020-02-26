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
* @param orders An element of elevator_orders providing
* the order table and priority queue.
* @param controller An element of elevator_controller
* providing the previous direction, previous floor and
* the present state.
*
*/

void decide_next_order_at_floor(elevator_orders *orders, elevator_controller *controller);

/**
 * @brief Decides whether the elevator is to stop at the
 * given floor or not.
 * 
 * @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state.  
 */

void decide_to_stop_at_floor(elevator_orders *orders, elevator_controller *controller);

/**
 * @brief Controls the floor sensor lights on the floor panel.
 */
void control_floor_indicator_lights();


/**
* @brief Drives the elevator if not at a floor it is to
* stop at.
*
* @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state. 
*/
void driving(elevator_orders *orders, elevator_controller *controller);

/**
 * @brief Operations connected to stopping at a floor; 
 * dequeueing the floor, opens and closes the door, and
 * decides what the next order is to be.
 * 
 * @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state.  
 *
 */
void stopping_at_floor(elevator_orders *orders, elevator_controller *controller);

/**
 * @brief Checks for new orders. When a new element arrives
 * the queue, decide_next_order_at_floor is called.
 *
 * @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state. 
 *
 */
void idle(elevator_orders *orders, elevator_controller *controller);

/**
 * @brief Initializes the elevator. Reads and acts on stop
 * signal, and switches between the remaining states.
 *
 * @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state. 
 *
 */

void control_elevatorNimbus2000(elevator_orders *orders, elevator_controller *controller);


#endif
