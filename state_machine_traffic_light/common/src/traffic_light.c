#include "traffic_light.h"
#include <stdio.h>
#include <unistd.h>

traffic_light_state current_state = green_light;
void green_light(void)
{
    printf("Green Light, sleep for 4 secs\n");
    sleep(4);
    printf("Green light is Done, change state to Yellow\n");
    current_state = yellow_light;

}

void yellow_light(void)
{
    printf("yellow_light, sleep for 2 secs\n");
    sleep(2);
    printf("Yellow light is Done, change state to Red\n");
    current_state = red_light;

}

void red_light(void)
{
    printf("red_light, sleep for 3 secs\n");
    sleep(3);
    printf("Red light is Done, change state to Green\n");
    current_state = green_light;

}