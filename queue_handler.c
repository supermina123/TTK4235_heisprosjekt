#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "queue_handler.h"


void qh_add_order_in_priority_queue(int *priority, int f) {
    for (int i = 0; i<HARDWARE_NUMBER_OF_FLOORS; i++) {
        if (priority[i]== -1) {
            priority[i] = f;
        }
    }
}



void qh_fill_orders(int *orders, int *priority) {
    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
            /* Internal orders */
        if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
            orders[f][2] = 1;
            qh_add_order_in_priority_queue(*priority, f);
            //hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 1);
        }

            /* Orders going up */
        if(hardware_read_order(f, HARDWARE_ORDER_UP)){
            orders[f][1] = 1;
            qh_add_order_in_priority_queue(*priority, f);
            //hardware_command_order_light(f, HARDWARE_ORDER_UP, 1);
        }

            /* Orders going down */
        if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
            orders[f][0] = 1;
            qh_add_order_in_priority_queue(*priority, f);
            //hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 1);
        }
    }
}

/*
void qh_dequeue(int *priority, int f) {
    for(int i = 0; i<HARDWARE_NUMBER_OF_FLOORS; i++) {

    }
}
*/


