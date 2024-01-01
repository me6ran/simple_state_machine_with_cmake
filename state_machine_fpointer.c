#include <stdio.h>
#include "traffic_light.h"
#include "math_operations.h"


typedef enum {false, true} bool;




int (* const op_pointer[]) (int, int) = {add, sub};

int main(void)
{
    
    
    while(true)
    {
        current_state();
    }

    return 0;
}