#include <stdio.h>
#include <stdlib.h>
#include "elevator.h"



void elevator_initialize(elevator_controller *controller){
	while(!elevator_at_floor(controller)){
		elevator_set_motor_direction(controller, HARDWARE_MOVEMENT_UP);
	}
	elevator_set_motor_direction(controller, HARDWARE_MOVEMENT_STOP);
	controller->state = IDLE_STATE;
}

elevator_direction elevator_get_last_direction(elevator_controller *controller) {
	return controller->last_dir;
}

void elevator_update_last_floor(elevator_controller *controller, int f) {
	controller->last_floor = f;
}


void elevator_set_motor_direction(elevator_controller *controller, HardwareMovement new_movement) {
	hardware_command_movement(new_movement);
	if (new_movement == HARDWARE_MOVEMENT_UP) {
		controller->last_dir = UP;
	}
	if (new_movement == HARDWARE_MOVEMENT_DOWN) {
		controller->last_dir = DOWN;
	}
}

int elevator_at_floor(elevator_controller *controller) {
	for (int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++) {
		if (hardware_read_floor_sensor(f)) {
			elevator_update_last_floor(controller, f);
			return 1;
		}
	}
	return 0;
}

void elevator_stop_at_floor(elevator_controller *controller){
	elevator_set_motor_direction(controller, HARDWARE_MOVEMENT_STOP);
}



