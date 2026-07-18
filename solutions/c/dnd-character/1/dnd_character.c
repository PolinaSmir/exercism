#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>

int ability(void) {
    int arr[4];
    int min = 7;
    int indexMin;
    for(int i = 0; i<5; i++) {
        int randNum = (rand() % 6) + 1;
        if(randNum < min) {
            min = randNum;
            indexMin = i;
        }
        arr[i] = randNum;
    }
    // Score summary
    int score = 0;
    for(int j=0; j<4; j++) {
        if(indexMin == j)
            continue;
        score += arr[j];
    }
    return score;
}
int modifier(int score) {
    return floor(((double)(score - 10) / 2));
}
dnd_character_t make_dnd_character(void) {
    dnd_character_t character;
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints = 10 + modifier(character.constitution);
    return character;
}