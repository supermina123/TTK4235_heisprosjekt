#ifndef DOOR_H
#define DOOR_H
#include <time.h>

/**
* @file
* @brief Handles the door
*/

/**
* @brief Int showing whether or not
* door is open.
*/
//int is_door_open;

//void door_start_timer();
void initialize_time();
/**
* @brief Pointer to when the door
* was opened.
*/
//time_t door_time_opened_pointer;


/**
* @brief Keeps the door open when 1,
* and closed when 0.
*/

int door_keep_open();

/**
* @brief Fetches the status of the door.
* 0 means closed door,
* 1 means open door.
*
*/
int door_get_status();

/**
* @brief Opens the door and sets the
* is_door_open int pointer to 1.
*
*/
void door_open();

/**
* @brief Closes the door and sets the
* is_door_open int pointer to 0.
* 
*/

void door_close();


#endif
