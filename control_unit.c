#include <stdio.h>
#include <stdlib.h>
#include "control_unit.h"
#include "elevator.h"
#include "queue_handler.h"





void driving(elevator_orders *orders, elevator_controller *controller){
	elevator_at_ends(controller); //fjern denne etterhvert
	if (elevator_at_floor(controller)) {
		decide_to_stop_at_floor(orders, controller);
	}
}

void decide_to_stop_at_floor(elevator_orders *orders, elevator_controller *controller){
	if (orders->order_table[controller->last_floor][controller->last_dir] | orders->priority_queue[0]){
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
			elevator_set_motor_direction(controller, HARDWARE_MOVEMENT_UP);
		}
		else{
			elevator_set_motor_direction(controller,HARDWARE_MOVEMENT_DOWN);
		}
		controller->state = DRIVING_STATE;
	}
}


	
	
	
	
	
	
	

