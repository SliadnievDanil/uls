#include "../inc/uls.h"

int get_max_size(t_file** files) {
    t_file *file = *files;
    int max_lenght = 0;
    while(file) {
        int len = mx_strlen(file->size);
        if(len > max_lenght) {
            max_lenght = len;
        }
        file = file->next;
    }
    return max_lenght;
}

