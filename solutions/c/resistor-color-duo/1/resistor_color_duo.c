#include "resistor_color_duo.h"
#include <math.h>

uint16_t color_code(const resistor_band_t arr[]) {
    uint16_t code = 0;
    for(int i = 0; i<2; i++) {
        code += (int)arr[i]*pow(10, 1-i);
    }
    return code;
}