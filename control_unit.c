#include <stdio.h>
#include <stdlib.h>
#include "control_unit.h"



/*
void driving(elevator_orders *orders, elevator_states *state){
	elevator_at_ends();
	if (elevator_at_floor()) {
		floor_to_stop = elevator_get_last_floor();
	}
}*/

void decide_next_order_at_floor(elevator_orders *orders, elevator_state *state){
	next_in_queue = orders->priority_queue[0];
	if (next_in_queue == -1){
		*state = IDLE_STATE;
	}
	else {
		if (next_in_queue < elevator_get_last_floor()){
			elevator_set_motor_direction(HARDWARE_MOVEMENT_UP);
		}
		else{
			elevator_set_motor_direction(HARDWARE_MOVEMENT_DOWN);
		}
		*state = DRIVING_STATE
	}
}