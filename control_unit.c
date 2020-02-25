#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Slett når dørtimer er gudd
#include "control_unit.h"
#include "elevator.h"
#include "queue_handler.h"
#include "door.h"






void driving(elevator_orders *orders, elevator_controller *controller){
	if (elevator_at_floor(controller)) {
		decide_to_stop_at_floor(orders, controller);
	}
}

void decide_to_stop_at_floor(elevator_orders *orders, elevator_controller *controller){
	if (orders->order_table[controller->last_floor][controller->last_dir]){
		elevator_stop_at_floor(controller);
		controller->state = STOP_AT_FLOOR_STATE;
	}
	if (orders->priority_queue[0]==controller->last_floor){
		elevator_stop_at_floor(controller);
		controller->state = STOP_AT_FLOOR_STATE;
	}
}	

void decide_next_order_at_floor(elevator_orders *orders, elevator_controller *controller){
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
void control_floor_indicator_lights(){
	for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        if(hardware_read_floor_sensor(f)){
        	hardware_command_floor_indicator_on(f);
        }
    }
}

void stopping_at_floor(elevator_orders *orders, elevator_controller *controller){
	qh_dequeue(orders, controller->last_floor);
	if (door_get_status()){
		if(!door_keep_open()){
			door_close();
			decide_next_order_at_floor(orders, controller);
		}
	}
	else{
		door_open();
	}
	
}

void idle(elevator_orders *orders, elevator_controller *controller){ //idle bare i en etasje
	if(!qh_is_queue_empty(orders)){
		decide_next_order_at_floor(orders, controller);
	}
}
void emergency_stop(elevator_orders *orders, elevator_controller *controller){
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

void control_elevatorNimbus2000(elevator_orders *orders, elevator_controller *controller){
	
	elevator_initialize(controller);

	while(1){

        if(hardware_read_stop_signal()){
            controller->state = EMERGENCY_STOP_STATE;
        }
        qh_fill_orders(orders);
        control_floor_indicator_lights();

        switch(controller->state){
            
            case IDLE_STATE:
                idle(orders, controller);
                break; 

            case DRIVING_STATE:
                driving(orders, controller);
                break;
              
            case STOP_AT_FLOOR_STATE:
		        stopping_at_floor(orders, controller);
                break;

            case EMERGENCY_STOP_STATE:
                emergency_stop(orders, controller);
                break;
        }
    }
}
	
	
	
	
	
	
	

