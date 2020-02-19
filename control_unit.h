#include "hardware.h"

/*
typedef enum {INIT_STATE, 
                DRIVING_STATE, 
                STOP_AT_FLOOR_STATE, 
                EMERGENCY_STOP_STATE, 
                IDLE_STATE} elevator_state;
*/

typedef struct {
    int order_tabel[HARDWARE_NUMBER_OF_FLOORS][3];
    int priority_queue[HARDWARE_NUMBER_OF_FLOORS];
}elevator_orders;



int check_orders_at_floor(elevator_orders order, int f); 

