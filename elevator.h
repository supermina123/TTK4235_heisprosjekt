
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
* @brief Defines an enum of the possible 
* states the elevator can hold.
*
*/
typedef enum {DRIVING_STATE, 
              STOP_AT_FLOOR_STATE, 
              EMERGENCY_STOP_STATE, 
              IDLE_STATE} elevator_state;

/**
* @brief Defines an enum with the possible 
* directions the elevator can hold
*/
typedef enum {
	DOWN,
	UP}elevator_direction;


/**
* @brief Defines a struct containing the 
* previous direction, previous floor and 
* the present state.
*/


typedef struct elevator_controller{
    elevator_direction last_dir;
	int last_floor;
	elevator_state state;
}elevator_controller;




void elevator_initialize(elevator_controller *controller);

/** 
* @brief Gets last direction of elevator
*/
elevator_direction elevator_get_last_direction(elevator_controller *controller);

/**
* @brief Updates last direction of elevator
* 
* @param f Last floor
*/
void elevator_update_last_floor(elevator_controller *controller, int f);



/**
* @brief Decides new motor direction
* 
* @param new_movement The new direction of 
* the motor
*
*/
void elevator_set_motor_direction(elevator_controller *controller, HardwareMovement new_movement);

/**
* @brief checks whether the elevator is at
* a floor, and updates which floor was the 
* previous floor.
*
*/
int elevator_at_floor(elevator_controller *controller);

/**
* @brief Stops the motor of the elevator
*/
void elevator_stop_at_floor(elevator_controller *controller);

/**
* @brief Orders the elevator down if it's at the
* top, and up if it's at the bottom.
*
*/
int elevator_at_ends();


#endif
