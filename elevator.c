#include <stdlib.h>
#include "elevator.h"
#include "hardware.h"

int last_floor = 0;
elevator_direction last_dir = UP;
HardwareMovement movement = HARDWARE_MOVEMENT_STOP;


elevator_direction elevator_get_last_direction() {
	return last_dir;
}

void elevator_update_last_floor(int f) {
	last_floor = f;
}

int elevator_get_last_floor() {
	return last_floor;
}

void elevator_set_motor_direction(HardwareMovement new_movement) {
	hardware_command_movement(new_movement);
	if (new_movement == HARDWARE_MOVEMENT_UP) {
		last_dir = UP;
	}
	if (new_movement == HARDWARE_MOVEMENT_DOWN) {
		last_dir = DOWN;
	}
}

int elevator_at_floor() {
	for (int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++) {
		if (hardware_read_floor_sensor(f)) {
			elevator_update_last_floor(f);
			return 1;
		}
	}
	return 0;
}

void elevator_stop_at_floor() {
	elevator_set_motor_direction(HARDWARE_MOVEMENT_STOP);
}

void elevator_at_ends() {
	if (hardware_read_floor_sensor(0)) {
		hardware_command_movement(HARDWARE_MOVEMENT_UP);
	}
	if (hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)) {
		hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
	}
}




