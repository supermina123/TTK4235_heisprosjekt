#ifndef QUEUE_HANDLER_H
#define QUEUE_HANDLER_H
#include "hardware.h"

/**
* @file
* @brief Handle the priority queue
* and order table
*
*/

/**
* @brief Define a struct containing an order
* table in the shape of a HARDWARE_NUMBER_OF_FLOORS*3 
* matrix, and a priority queue with 
* HARDWARE_NUMBER_OF_FLOORS entries.
*
*/
typedef struct elevator_orders{
    int order_table[HARDWARE_NUMBER_OF_FLOORS][3]; /**< struct member order table */
    int priority_queue[HARDWARE_NUMBER_OF_FLOORS]; /**< struct member priority queue*/
}elevator_orders;



/**
* @brief Add an order in the pririty queue.
* 
* @param orders An element of elevator_orders
* containing an order table and a priority queue.
* @param f The floor at which the queue entries
* are to be added at.
*
*/
void qh_add_order_in_priority_queue(elevator_orders *orders, int f);

/**
* @brief Fill the elevator order table and
* priority queue. 
*
* @param orders The orders with which to fill
* the order table. 
*
*/
void qh_fill_orders(elevator_orders *orders);


/**
* @brief Delete an order from the priority queue
* and order table when the given floor is reached.
* Turn off correlating order lights. 
*
* @param orders The element of elevator_orders which 
* is to be dequeued.
* @param f The floor at which the dequeuing is to 
* happen. 
*/
void qh_dequeue(elevator_orders *orders, int f);


/**
* @brief Check whether or not the queue
* is empty.
*
* @param orders The order table to be checked in 
* order to deide whether the queue is empty.
*
* @return 0 if queue empty
* @return 1 if there are entries in queue
*/
int qh_is_queue_empty(elevator_orders *orders);


/**
* @brief Delete all orders from order table
* and the priority queue.
*
* @param orders The order table which is to be
* deleted by this function. 
*/
void qh_delete_all_orders(elevator_orders *orders);

/**
* @brief Check if there are orders at a given floor.
*
* @param order The order table which supplies orders. 
* An element of elevator_orders providing an order
* table and a priority queue. 
* @param f The floor at which to check whether there
* are orders or not. 
*/

int qh_orders_at_floor(elevator_orders order, int f); 

/**
* @brief Turn off all order lights.
*/
void qh_clear_all_order_lights();



/**
* @brief Prints order
*
* @param orders
*/
void print_orders(elevator_orders *orders);


#endif


