#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H
#include "hardware.h"
#include "elevator.h"
#include "queue_handler.h"

/**
* @file 
* @brief A control unit controlling the elevator.
*
*/

elevator_orders orders;
elevator_controller ctrl;

int next_in_queue;


/**
* @brief Decide what to do with the next 
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
 * @brief Decide whether the elevator is to stop at the
 * given floor or not.
 * 
 * @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state.  
 */

void decide_to_stop_at_floor(elevator_orders *orders, elevator_controller *controller);

/**
 * @brief Control the floor sensor lights on the floor panel.
 */
void control_floor_indicator_lights();

/**
* @brief Drive the elevator as long as at a different
* than destination floor.
*
* @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state. 
*/
void driving(elevator_orders *orders, elevator_controller *controller);

/**
 * @brief Operations connected to stopping at a floor; 
 * dequeue the floor, open and close the door, and
 * decide next order.
 * 
 * @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state.  
 */
void stopping_at_floor(elevator_orders *orders, elevator_controller *controller);

/**
 * @brief Check for new orders. If the queue is not empty,
 * call decide_next_order_at_floor.
 *
 * @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state. 
 */
void idle(elevator_orders *orders, elevator_controller *controller);

/**
 * @brief Initialize the elevator. Read and act on stop
 * signal, and switche between the remaining states.
 *
 * @param orders An element of elevator_orders providing                            * the order table and priority queue.                                              * @param controller An element of elevator_controller                              * providing the previous direction, previous floor and                             * the present state. 
 */
void control_elevatorNimbus2000(elevator_orders *orders, elevator_controller *controller);


#endif
