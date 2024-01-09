#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

/* Function prototypes for the traffic light system */

/* Turns on the green light */
void green_light(void);

/* Turns on the yellow light */
void yellow_light(void);

/* Turns on the red light */
void red_light(void);

/* Function pointer type for traffic light state */
typedef void (* traffic_light_state)(void);

extern traffic_light_state current_state;
// current_state = green_light;

typedef enum 
{
    GREEN,
    RED,
    YELLOW,
} state_machine_cfg_t;

#endif /* TRAFFIC_LIGHT_H */