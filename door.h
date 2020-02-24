#ifndef DOOR_H
#define DOOR_H
//int door_keep_open();

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
