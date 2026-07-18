#include "luhn.h"
#include <string.h>
#include <stdlib.h>

bool luhn(const char *num) {
    if(strlen(num) <= 1) {
        return false;
    }
    // Trim spaces
    // Gaps in new string so add different iterator to move
    //you were counting with values of ASCII forgot to convert
    // When copying you need to close the string with \0, so allocate length+1 and on final iteration newArr[j]='\0' to close string
    
    char* newArr = (char*)malloc(strlen(num)*sizeof(char));
    size_t j = 0;
    for(size_t i = 0; i<strlen(num); i++) {
        if(num[i] != ' ') {
            if(num[i] - '0' > 9) {
                return false;
            }
            newArr[j++] = num[i] - '0';
        }
    }
    newArr[j]='\0';
    
    size_t actualLength = j;

    if(actualLength <= 1) {
        return false;
    }
    
    int even = 0;
    int sum = 0;
    if(actualLength % 2 == 0) {
        even = 1;
    }
    for(size_t i = 0; i<actualLength; i++) {
        if(even) {
            if(i % 2 == 0) {
                if(newArr[i]*2 > 9) {
                   newArr[i] = newArr[i]*2-9;
                } else {
                    newArr[i] = newArr[i]*2;
                }
            }
        } else {
            if(i % 2 != 0) {
                if(newArr[i]*2 > 9) {
                   newArr[i] = newArr[i]*2-9;
                } else {
                    newArr[i] = newArr[i]*2;
                }
            }
        }
        sum += newArr[i];
    }

    if(sum % 10 != 0) {
        return false;
    }

    return true;  
}