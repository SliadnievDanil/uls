#include "../inc/uls.h"

void printl(t_flag *flags, int argc, char **argv) {
    if(argc == 2) {
        print_current_l(flags, NULL, NULL);
    }
    else {
        print_all_l(argv, flags, argc);
    }
}

