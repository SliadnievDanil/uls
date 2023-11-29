#include "../inc/uls.h"

int get_num_tabs(int width, int len) {
    int dif = width - len;
    if(dif % 8 != 0) {
        return dif / 8 + 1;
    }
    else {
        return dif / 8;
    }
}

