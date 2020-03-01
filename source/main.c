
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "control_unit.h"

int main(){

    elevator_orders orders;
    orders = (elevator_orders){ .order_table = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}}, .priority_queue = {-1,-1,-1,-1}};
    elevator_controller ctrl;
    ctrl = (elevator_controller){ .last_dir = UP, .last_floor = 0, .state = DRIVING_STATE};
    
    ctrl_operate_elevator(&orders,&ctrl);

    return 0;
}
