#include "clock.h"

clock_t clock_create(int hour, int minute) {
    clock_t clock;
    // int actualHours;
    // int actualMinutes;
    // Processing big numbers
    int hoursOutOfMinutes = minute/60 + hour;
    int actualMinutes = minute % 60;
    int actualHours = hoursOutOfMinutes % 24;
    
    if(hour < 0) {
        actualHours = (actualHours % 24) + 24;
    }
    if(minute < 0) {
        actualMinutes = (minute % 60) + 60;
        actualHours -= 1;
        // actualHours = (hour % 24) + 24;
        if(actualHours < 0) {
            actualHours = (actualHours % 24) + 24;
        }
        
        int addHours = actualMinutes / 60;
        if(addHours) {
            actualHours += addHours;
            if(!(actualMinutes % 60)) {
                actualMinutes = 0;
            }
        }
    }
    
    // Printing hours and minutes
    if(actualHours > 9 && actualHours < 24) {
        int tensHour = actualHours / 10;
        int onesHour = actualHours % 10;
        clock.text[0] = '0' + tensHour;
        clock.text[1] = '0'+ onesHour;
    } else {
        clock.text[0] = '0';
        clock.text[1] = '0'+actualHours;
    }
    clock.text[2] = ':';
    if(actualMinutes > 9) {    
        int tensMinute = actualMinutes / 10;
        int onesMinute = actualMinutes % 10;
        clock.text[3] = '0' + tensMinute;
        clock.text[4] = '0'+ onesMinute;
    } else {
        clock.text[3] = '0';
        clock.text[4] = '0'+ actualMinutes;
    }
    clock.text[5] = '\0';
    
    return clock;  
}
clock_t clock_add(clock_t clock, int minute_add) {
    // Get hours and minutes value
    int hours = 0;
    int minutes = 0;
    for(long unsigned int i=0; i<MAX_STR_LEN; i++) {
        if(clock.text[i] != '0') {
            if(i == 0) {
                hours += (clock.text[i]-'0')*10;
            }
            if(i==1) {
                hours += clock.text[i]-'0';
            }
            if(i==3) {
                minutes += (clock.text[i]-'0')*10;
            }
            if(i==4) {
                minutes += clock.text[i]-'0';
            }
        }
    }
    int sumTime = minutes+hours*60 + minute_add;

    hours = sumTime / 60;
    minutes = sumTime % 60;
    clock_t newClock = clock_create(hours, minutes);
    
    return newClock;
}
clock_t clock_subtract(clock_t clock, int minute_subtract) {
    // Get hours and minutes value
    int hours = 0;
    int minutes = 0;
    for(long unsigned int i=0; i<MAX_STR_LEN; i++) {
        if(clock.text[i] != '0') {
            if(i == 0) {
                hours += (clock.text[i]-'0')*10;
            }
            if(i==1) {
                hours += clock.text[i]-'0';
            }
            if(i==3) {
                minutes += (clock.text[i]-'0')*10;
            }
            if(i==4) {
                minutes += clock.text[i]-'0';
            }
        }
    }
    int sumTime = minutes+hours*60 - minute_subtract;

    hours = sumTime / 60;
    minutes = sumTime % 60;
    clock_t newClock = clock_create(hours, minutes);
    
    return newClock;
}
bool clock_is_equal(clock_t a, clock_t b) {
    for(long unsigned int i=0; i<MAX_STR_LEN; i++) {
        if(a.text[i] != b.text[i]) {
            return false;
        }
    }
    return true;
}