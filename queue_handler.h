#ifndef QUEUE_HANDLER_H
#define QUEUE_HANDLER_H


/**
* @file
* @brief handles the order queue
* and order table
*
*/

/**
* @brief Defines a struct containing an order
* table in the shape of a HARDWARE_NUMBER_OF_FLOORS*3 
* matrix, and a priority queue with 
* HARDWARE_NUMBER_OF_FLOORS entries.
*
*/
typedef struct elevator_orders{
    int order_table[HARDWARE_NUMBER_OF_FLOORS][3];
    int priority_queue[HARDWARE_NUMBER_OF_FLOORS];
}elevator_orders;



/**
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
* @param orders
*
*/
void qh_fill_orders(elevator_orders *orders);


/**
* @brief Deletes an order from the queue
* when the given floor is reached
*
* @param orders
* @param f
*/
void qh_dequeue(elevator_orders *orders, int f);


/**
* @brief Checks whether or not the queue
* is empty.
*
* @param orders
*
* @return 0 if queue empty
* 1 if there are entries in queue
*/
int qh_is_queue_empty(elevator_orders *orders);


/**
* @brief Deletes all orders from order matrix
* and the priority queue
*
* @param orders
*/
void qh_delete_all_orders(elevator_orders *orders);

/**
* @brief Checks if there are orders at a floor f.
*
* @param order
* @param f
*/

int qh_orders_at_floor(elevator_orders order, int f); 



/**
* @brief Prints order
*
* @param orders
*/
void print_orders(elevator_orders *orders);


#endif


