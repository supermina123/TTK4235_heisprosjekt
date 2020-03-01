
#include <stdio.h>
#include <stdlib.h>
#include "queue_handler.h"



void qh_add_order_in_priority_queue(elevator_orders *orders, int f) {
    for (int i = 0; i<HARDWARE_NUMBER_OF_FLOORS; i++) {
        if (orders->priority_queue[i]== f){
            i = HARDWARE_NUMBER_OF_FLOORS;
        }
        if (orders->priority_queue[i]== -1){
            orders->priority_queue[i] = f;
            i = HARDWARE_NUMBER_OF_FLOORS;
        }
    }
}


void qh_fill_orders(elevator_orders *orders) {
    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
            /* Internal orders */
        if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
            orders->order_table[f][2] = 1;
            qh_add_order_in_priority_queue(orders, f);
            hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 1);
        }
            /* Orders going up */
        if(hardware_read_order(f, HARDWARE_ORDER_UP)){
            orders->order_table[f][1] = 1;
            qh_add_order_in_priority_queue(orders, f);
            hardware_command_order_light(f, HARDWARE_ORDER_UP, 1);
        }
            /* Orders going down */
        if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
            orders->order_table[f][0] = 1;
            qh_add_order_in_priority_queue(orders, f);
            hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 1);
           
        }
    }
}




void qh_dequeue(elevator_orders *orders, int f) {
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++) {
        if (orders->priority_queue[i] == f) {
            while (i<HARDWARE_NUMBER_OF_FLOORS-1) {
               orders->priority_queue[i] = orders->priority_queue[i+1];     //Move the rest of the orders forward
               i++;

            }
            orders->priority_queue[HARDWARE_NUMBER_OF_FLOORS-1] = -1;       //Set the last elemetnt to -1 (empty)
        }
    }
    for(int i = 0; i<3; i++) {                                                  //Delete row in order table. (All people entering)
        orders->order_table[f][i] = 0;
    }
    hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 0);
    hardware_command_order_light(f, HARDWARE_ORDER_UP, 0);
    hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 0);
}

int qh_is_queue_empty(elevator_orders *orders){
    for(int i = 0; i<HARDWARE_NUMBER_OF_FLOORS; i++) {
        if (orders->priority_queue[i]!=-1) {
            return 0;
        }
    }
    return 1;
}

void qh_delete_all_orders(elevator_orders *orders){
    for (int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        orders->order_table[f][0] = 0;
        orders->order_table[f][1] = 0;
        orders->order_table[f][2] = 0;
        orders->priority_queue[f] = -1;
        hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 0);
        hardware_command_order_light(f, HARDWARE_ORDER_UP, 0);
        hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 0);
    }

    
}

int qh_orders_at_floor(elevator_orders orders, int f) {
    for(int i = 0; i < 3; i++) {
        if (orders.order_table[f][i]==1) {
            return 1;
        }
    }
    return 0;
}

void print_orders(elevator_orders *orders){
    printf("\nPRIORITY QUEUE:\n");
    for(int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; i++){
        printf(" %d", orders->priority_queue[i]+1);
    }
    printf("\nORDER TABLE:\n");
    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        printf("Floor %d\n", f+1);
        printf("Down: %d Up: %d Inside: %d\n", orders->order_table[f][0], orders->order_table[f][1], orders->order_table[f][2]);
    }
    printf("\n");

}

void qh_clear_all_order_lights(){
    HardwareOrder order_types[3] = {
        HARDWARE_ORDER_UP,
        HARDWARE_ORDER_INSIDE,
        HARDWARE_ORDER_DOWN
    };

    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        for(int i = 0; i < 3; i++){
            HardwareOrder type = order_types[i];
            hardware_command_order_light(f, type, 0);
        }
    }
}




