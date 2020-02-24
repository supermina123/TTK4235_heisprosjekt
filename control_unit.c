#include <stdio.h>
#include <stdlib.h>
#include "control_unit.h"




void driving(elevator_orders *orders, elevator_controller *controller){
	elevator_at_ends();
	if (elevator_at_floor()) {
		decide_to_stop_at_floor(orders, controller)
	}
}

vois decide_to_stop_at_floor(elevator_orders *orders, elevator_controller *controller){
	floor_to_stop = elevator_get_last_floor();
	dir_elevator = elevator_get_last_direction();
	if (orders->order_table[floor_to_stop][dir_elevator] | orders->priority_queue[0]){
		elevator_stop_at_floor();
		controller->state = STOP_AT_FLOOR_STATE;
	}
}	

void decide_next_order_at_floor(elevator_orders *orders, elevator_controller *controller){
	next_in_queue = orders->priority_queue[0];
	if (next_in_queue == -1){
		controller->state = IDLE_STATE;
	}
	else {
		if (next_in_queue < elevator_get_last_floor()){
			elevator_set_motor_direction(HARDWARE_MOVEMENT_UP);
		}
		else{
			elevator_set_motor_direction(HARDWARE_MOVEMENT_DOWN);
		}
		controller->state = DRIVING_STATE;
	}
}

void stop_at_floor(elevator_orders *orders, elevator_controller *controller){
	//dequeue at floor
}	
	
	
	
	
	
	
	

