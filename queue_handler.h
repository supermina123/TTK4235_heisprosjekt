#ifndef QUEUE_HANDLER_H
#define QUEUE_HANDLER_H
#include "control_unit.h"



void qh_add_order_in_priority_queue(elevator_orders *orders, int f);

void qh_fill_orders(elevator_orders *orders, int *priority);

void qh_dequeue(elevator_orders *orders, int f);

int qh_is_queue_empty(elevator_orders *orders);


#endif


