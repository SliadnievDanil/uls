#include "../inc/uls.h"

bool is_flag(char flag) {
    for(int i = 0; i < 16; i++) {
        if(flag == FLAGS[i]) {
            return true;
        }       
    }
    return false;
}

