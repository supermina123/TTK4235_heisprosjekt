#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "hardware.h"

/**
* @file
* 
* @brief Håndterer heis
* 
*/





typedef enum {
	UP,
	DOWN
}elevator_direction;

extern int last_floor;
extern elevator_direction last_dir;
extern HardwareMovement movement;

elevator_direction elevator_get_last_direction();

void elevator_update_last_floor(int f);

int elevator_get_last_floor();

void elevator_set_motor_direction(HardwareMovement new_movement);

int elevator_at_floor();

void elevator_stop_at_floor();

void elevator_at_ends();


#endif
