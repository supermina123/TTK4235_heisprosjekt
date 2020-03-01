#ifndef DOOR_H
#define DOOR_H
#include <time.h>

/**
* @file
* @brief A handler controlling operations 
* connected to the door.
*
*/


int door_keep_open(); /**< used to keep door open if ==1, and close if ==0> */

/**
* @brief Fetch door status.
* 
* @return 0 means closed door
* * @return 1 means open door.
*/
int door_get_status(); 

/**
* @brief Open the door and set the @p
* is_door_open int to 1.
*/
void door_open();

/**
* @brief Close the door and set the @p
* is_door_open int to 0.
* 
*/
void door_close();


#endif
