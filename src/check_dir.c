#include "../inc/uls.h"

bool check_dir(char **argv, int argc) {
    for(int i = 1; i < argc; i++) {
    if(argv[i][0] == '-' && mx_strlen(argv[i]) > 1) {
    } else {
        return 1;
    }
    }
    return 0;
}

