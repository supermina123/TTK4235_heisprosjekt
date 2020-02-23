#include <stdio.h>
#include <stdlib.h>
#include "control_unit.h"



int check_orders_at_floor(elevator_orders orders, int f) {
    for(int i = 0; i < 3; i++) {
        if (orders.order_table[f][i]==1) {
            return 1;
        }
    }
    return 0;
}