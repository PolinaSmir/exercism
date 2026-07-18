#include "darts.h"
#include <math.h>

uint8_t score(coordinate_t landing_position) {
    float distanceLanding = sqrt(pow(landing_position.x, 2) + pow(landing_position.y, 2));

    if(distanceLanding<=1) {
        return 10;
    } else if(distanceLanding<=5) {
        return 5;
    } else if(distanceLanding<=10) {
        return 1;
    }
    return 0;
}