#include "space_age.h"

float age(planet_t planet, int64_t seconds) {
    // seconds divide by seconds of 1 year on Earth
    // then divide by planets Orbital period in Earth Years
    float result = seconds / 31557600;
    switch(planet) {
        case MERCURY:
            result = result / 0.2408467;
            break;
        case VENUS:
            result = result / 0.61519726;
            break;
        case EARTH:
            result = result / 1.0;
            break;
        case MARS:
            result = result / 1.8808158;
            break;
        case JUPITER:
            result = result / 11.862615;
            break;
        case SATURN:
            result = result / 29.447498;
            break;
        case URANUS:
            result = result / 84.016846;
            break;
        case NEPTUNE:
            result = result / 164.79132;
            break;
        default:
            result = -1;
    }
    return result;
}