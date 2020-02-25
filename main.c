
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hardware.h"
#include "door.h"
#include "control_unit.h"
#include "queue_handler.h"
#include "elevator.h"

static void clear_all_order_lights(){
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


int main(){
    

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

/*
    clear_all_order_lights();
    //hardware_command_movement(HARDWARE_MOVEMENT_UP);

    elevator_orders orders;
    orders = (elevator_orders){ .order_table = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}}, .priority_queue = {-1,-1,-1,-1}};

    elevator_controller ctrl;
    ctrl = (elevator_controller){ .last_dir = UP, .last_floor = 0, .state = DRIVING_STATE};
    

    int on = 1;

    elevator_set_motor_direction(&ctrl, HARDWARE_MOVEMENT_UP);
    */

    elevator_orders orders;
    orders = (elevator_orders){ .order_table = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}}, .priority_queue = {-1,-1,-1,-1}};
    print_orders(&orders);
    
    elevator_controller ctrl;
    ctrl = (elevator_controller){ .last_dir = UP, .last_floor = 0, .state = DRIVING_STATE};
    clear_all_order_lights();


    control_elevatorNimbus2000(&orders,&ctrl);

    return 0;
}

/* 
static void sigint_handler(int sig){
    (void)(sig);
    printf("Terminating elevator\n");
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    exit(0);
}

signal(SIGINT, sigint_handler);


 All buttons must be polled, like this: 
        for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
            if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
                hardware_command_floor_indicator_on(f);
            }
        }

        Lights are set and cleared like this:
        for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
             Internal orders 
            if(hardware_read_order(f, HARDWARE_ORDER_INSIDE)){
                hardware_command_order_light(f, HARDWARE_ORDER_INSIDE, 1);
            }

            if(hardware_read_order(f, HARDWARE_ORDER_UP)){
                hardware_command_order_light(f, HARDWARE_ORDER_UP, 1);
            }
            
            if(hardware_read_order(f, HARDWARE_ORDER_DOWN)){
                hardware_command_order_light(f, HARDWARE_ORDER_DOWN, 1);
            }
        }*/
