#include "../inc/uls.h"

int get_cols(int w_cols, int width) {
    int col = 0;
    if(w_cols / width != 0) {
        col = w_cols / width;
    }
    if(width*col > w_cols 
        && col != 1) {
            col--;
        }
    return col;
}

