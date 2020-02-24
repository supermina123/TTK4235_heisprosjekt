#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "hardware.h"

/**
* @file
* 
* @brief Handles the elevator
* 
*/

/**
* @brief Defines an enum with the possible 
* directions the elevator can hold
*/


typedef enum {
	DOWN,
	UP
}elevator_direction;

extern int last_floor;
extern elevator_direction last_dir;
extern HardwareMovement movement;



/** 
* @brief Gets last direction of elevator
*/
elevator_direction elevator_get_last_direction();

/**
* @brief Updates last direction of elevator
* 
* @param f Last floor
*/
void elevator_update_last_floor(int f);

/**
* @brief Returns last floor
*
*/
int elevator_get_last_floor();

/**
* @brief Decides new motor direction
* 
* @param new_movement The new direction of 
* the motor
*
*/
void elevator_set_motor_direction(HardwareMovement new_movement);

/**
* @brief checks whether the elevator is at
* a floor, and updates which floor was the 
* previous floor.
*
*/
int elevator_at_floor();

/**
* @brief Stops the motor of the elevator
*/
void elevator_stop_at_floor();

/**
* @brief Orders the elevator down if it's at the
* top, and up if it's at the bottom.
*
*/
void elevator_at_ends();


#endif
