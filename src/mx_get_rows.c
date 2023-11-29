#include "../inc/uls.h"

int get_rows(int col, int count) {
    int row = count / col;
    if(row == 0
        || count % col != 0) {
            row++;
        }
    return row;
}

