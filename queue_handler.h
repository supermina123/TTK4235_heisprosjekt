#ifndef QUEUE_HANDLER_H
#define QUEUE_HANDLER_H
#include "control_unit.h"

/**
* @file
* @brief handles the order queue
* and order table
*
*/

/*
* @brief Adds an order in the pririty queue.
* 
* @param orders
* @param f
*
*/

void qh_add_order_in_priority_queue(elevator_orders *orders, int f);


/**
* @brief fills the elevator order matrix
*
*/
void qh_fill_orders(elevator_orders *orders);


/**
* @brief Deletes an order from the queue
* when the given floor is reached
*
*/
void qh_dequeue(elevator_orders *orders, int f);


/**
* @brief Checks whether or not the queue
* is empty.
*
*/
int qh_is_queue_empty(elevator_orders *orders);


/**
* @brief Deletes all orders from order matrix
* and the priority queue
*
*/
void qh_delete_all_orders(elevator_orders *orders);



/**
* @brief Checks if there are orders at a floor f.
*
*/
int check_orders_at_floor(elevator_orders order, int f); 


/**
* @brief Prints order
*
*/
void print_orders(elevator_orders *orders);


#endif


