#include "../inc/uls.h"

int get_col_width(int max_lenght) {
    if(max_lenght % 8 == 0) {
        max_lenght += 8;
    }
    else {
        max_lenght += 8 - (max_lenght % 8);
    }
    return max_lenght;
}

