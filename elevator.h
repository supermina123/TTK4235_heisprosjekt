
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
*/typedef enum {
	DOWN,
	UP}elevator_direction;

/*! \struct elevator_controller
 * Defines a struct holding information about the direction, position and state
 * of the elevator.
 */
typedef struct elevator_controller{
	/*! The last known direction of the elevator*/	
	elevator_direction last_dir;
	/*! The last known floor of the elevator*/
	int last_floor;
	/*! The present elevator_state state of the elevator*/  
	elevator_state state;
}elevator_controller;



/**
 * @brief Bring the elevator to a defined state at a floor
 *
 * @param[out] controller When the elevator has reached a defined state, @p last_flo * or of @p controller is updated.
 */  
void elevator_initialize(elevator_controller *controller);

/**
* @brief Gets last direction of elevator
*/
elevator_direction elevator_get_last_direction(elevator_controller *controller);

/**
 * @brief Update the last floor @p f of @p controller.
 * 
 * @param[in] f Floor to update @p controller. 
 * @param[out] controller Controller of type elevator_controller.
 */
void elevator_update_last_floor(elevator_controller *controller, int f);



/**
* @brief Set motor direction of elevator_controller @p controller to
* @p new_direction.
* 
* @parameter[in] new_movement The new direction of enum type elevator_direction of 
* the motor.
* @param[out] controller Controller whose motor direction is set to @p new_movement. 
*/
void elevator_set_motor_direction(elevator_controller *controller, HardwareMovement new_movement);

/**
* @brief checks whether the elevator is at
* a floor, and updates which floor was the 
* previous floor.
*
* @param[out] controller Controller to uptade last_floor if the elevator is at a floor.
*
*/
int elevator_at_floor(elevator_controller *controller);

/**
* @brief Stops the motor of the elevator.
*
* @param[in] controller Controller to stop. 
*/
void elevator_stop_at_floor(elevator_controller *controller);


//int elevator_at_ends();


#endif
