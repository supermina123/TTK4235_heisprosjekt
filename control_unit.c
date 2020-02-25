#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Slett når dørtimer er gudd
#include "control_unit.h"
#include "elevator.h"
#include "queue_handler.h"






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

void stopping_at_floor(elevator_orders *orders, elevator_controller *controller){
	qh_dequeue(orders, controller->last_floor);
	sleep(2);
	decide_next_order_at_floor(orders, controller);
}

void idle(elevator_orders *orders, elevator_controller *controller){ //idle bare i en etasje
	if(qh_is_queue_empty(orders) != 1){
		decide_next_order_at_floor(orders, controller);

	}
}
	
	
	
	
	
	
	

