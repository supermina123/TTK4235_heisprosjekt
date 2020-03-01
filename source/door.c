#include "hardware.h"
#include "door.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define DOOR_OPEN_INTERVAL 3

int is_door_open = 0;

/*
time_t door_time_opened_pointer;
time_t *init_time = NULL;
door_time_opened_pointer = time(init_time);
*/

			//   Open = 1, closed = 0

/*
typedef struct {int *is_door_open,
                time_t *door_time_opened_pointer
} timeStruct;
*/


time_t door_time_opened_pointer;


int door_keep_open() {
	if (hardware_read_obstruction_signal()){
		door_time_opened_pointer = time(NULL);
		return 1;
	}
    if(time(NULL) < door_time_opened_pointer + DOOR_OPEN_INTERVAL) {
		return 1;
	}
	return 0;
}


int door_get_status() {
	return is_door_open;
}


void door_open() {
	hardware_command_door_open(1);
    door_time_opened_pointer = time(NULL);  //oppdater klokken
	is_door_open = 1;
}



void door_close() {
	hardware_command_door_open(0);
    is_door_open = 0;
}

