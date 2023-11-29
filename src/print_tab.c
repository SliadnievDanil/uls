#include "../inc/uls.h"

void mx_print_tab(int width, int len) {
    int count_tabs = get_num_tabs(width, len);
    for(int i = 0; i < count_tabs; i++) {
        mx_printstr("\t");
    }
}

