#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "queue_handler.h"
#include "control_unit.h"


void qh_add_order_in_priority_queue(elevator_orders *orders, int f) {
    for (int i = 0; i<HARDWARE_NUMBER_OF_FLOORS; i++) {
        if (orders->priority_queue[i]== -1) {
            orders->priority_queue[i] = f;
        }
    }
}


void qh_fill_orders(elevator_orders *orders, int *priority) {
    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
            /* Internal orders */
        if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
            orders->order_tabel[f][2] = 1;
            qh_add_order_in_priority_queue(orders, f);
            hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 1);
        }

            /* Orders going up */
        if(hardware_read_order(f, HARDWARE_ORDER_UP)){
            orders->order_tabel[f][1] = 1;
            qh_add_order_in_priority_queue(orders, f);
            hardware_command_order_light(f, HARDWARE_ORDER_UP, 1);
        }

            /* Orders going down */
        if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
            orders->order_tabel[f][0] = 1;
            qh_add_order_in_priority_queue(orders, f);
            hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 1);
        }
    }
}


void qh_dequeue(elevator_orders *orders, int f) {
    for(int i = 0; i<HARDWARE_NUMBER_OF_FLOORS; i++) {
        for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++) {
            if (orders->priority_queue[i] == f) {
                while (i<HARDWARE_NUMBER_OF_FLOORS-1) {
                   orders->priority_queue[i] = orders->priority_queue[i+1];     //Move the rest of the orders forward
                }
                orders->priority_queue[HARDWARE_NUMBER_OF_FLOORS-1] = -1;       //Set the last elemetnt to -1 (empty)
            }
        }
    }
    for(int i = 0; i<3; i++) {                                                  //Delete row in order table. (All people entering)
        orders->order_tabel[f][i] = 0;
    }
}

int qh_is_queue_empty(elevator_orders *orders){
    for(int i = 0; i<HARDWARE_NUMBER_OF_FLOORS; i++) {
        if (orders->priority_queue[i]==-1) {
            return 0;
        }
    }
    return 1;
}




