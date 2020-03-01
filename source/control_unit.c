#include <stdio.h>
#include <stdlib.h>
#include "control_unit.h"


void ctrl_driving(elevator_orders *orders, elevator_controller *controller){
	if (elevator_at_floor(controller)) {
		ctrl_decide_to_stop_at_floor(orders, controller);
	}
}

void ctrl_decide_to_stop_at_floor(elevator_orders *orders, elevator_controller *controller){
	if (orders->order_table[controller->last_floor][controller->last_dir]){
		elevator_stop_at_floor(controller);
		controller->state = STOP_AT_FLOOR_STATE;
	}
	if (orders->priority_queue[0]==controller->last_floor){
		elevator_stop_at_floor(controller);
		controller->state = STOP_AT_FLOOR_STATE;
	}
}	

void ctrl_decide_next_order_at_floor(elevator_orders *orders, elevator_controller *controller){
	next_in_queue = orders->priority_queue[0];
	if (next_in_queue == -1){
		controller->state = IDLE_STATE;
	}
	else {
		if (next_in_queue < controller->last_floor){
			elevator_set_motor_direction(controller, HARDWARE_MOVEMENT_DOWN);
		}
		else{
			elevator_set_motor_direction(controller,HARDWARE_MOVEMENT_UP);
		}
		controller->state = DRIVING_STATE;
	}
}
void ctrl_floor_indicator_lights(){
	for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        if(hardware_read_floor_sensor(f)){
        	hardware_command_floor_indicator_on(f);
        }
    }
}

void ctrl_stopping_at_floor(elevator_orders *orders, elevator_controller *controller){
	qh_dequeue(orders, controller->last_floor);
	if (door_get_status()){
		if(!door_keep_open()){
			door_close();
			ctrl_decide_next_order_at_floor(orders, controller);
		}
	}
	else{
		door_open();
	}
	
}

void ctrl_idle(elevator_orders *orders, elevator_controller *controller){ //idle bare i en etasje
	if(!qh_is_queue_empty(orders)){
		ctrl_decide_next_order_at_floor(orders, controller);
	}
}
void ctrl_emergency_stop(elevator_orders *orders, elevator_controller *controller){
	hardware_command_movement(HARDWARE_MOVEMENT_STOP);
	qh_delete_all_orders(orders);
	while(hardware_read_stop_signal()){
		hardware_command_stop_light(1);
		if(elevator_at_floor(controller)){
			door_open();
		}
	}
	hardware_command_stop_light(0);
	if(!door_keep_open()){
		door_close();
		controller->state = IDLE_STATE;
	}
}

void ctrl_operate_elevator(elevator_orders *orders, elevator_controller *controller){
	
	int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    } 

	qh_clear_all_order_lights();
	elevator_initialize(controller);

	while(1){

        if(hardware_read_stop_signal()){
            controller->state = EMERGENCY_STOP_STATE;
        }
        qh_fill_orders(orders);

        ctrl_floor_indicator_lights();

        switch(controller->state){
            
            case IDLE_STATE:
                ctrl_idle(orders, controller);
                break; 

            case DRIVING_STATE:
                ctrl_driving(orders, controller);
                break;
              
            case STOP_AT_FLOOR_STATE:
		        ctrl_stopping_at_floor(orders, controller);
                break;

            case EMERGENCY_STOP_STATE:
                ctrl_emergency_stop(orders, controller);
                break;
        }
    }
}
	
	
	
	
	
	
	

