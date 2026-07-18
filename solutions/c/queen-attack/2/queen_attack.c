#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if(queen_1.row == queen_2.row && queen_1.column == queen_2.column) {
        return INVALID_POSITION;
    }
    if(queen_1.row > 7 || queen_2.row > 7 ||
       queen_1.column > 7 || queen_2.column > 7) {
        return INVALID_POSITION;
    }
    
    for(int i=1; i<8; i++) {
        // position_t tempPosQ1 = queen_1;
        for(int x=-1; x<=1; x++) {
            for(int y=-1; y<=1; y++) {
                if(x == 0 && y==0) {
                    continue;
                }
                position_t tempPosQ1 = queen_1;
                tempPosQ1.row = y*i+tempPosQ1.row;
                tempPosQ1.column = x*i+tempPosQ1.column;  
                if(tempPosQ1.row == queen_2.row && 
                   tempPosQ1.column == queen_2.column) {
                    return CAN_ATTACK;
                }
                
                // if (tempPosQ1.row < 0 || tempPosQ1.row > 7 || 
                //     tempPosQ1.column < 0 || tempPosQ1.column > 7) {
                //     break;
                // }
                
                
            }
        }
    }
    
    
    return CAN_NOT_ATTACK;
}