#include "../inc/uls.h"

int get_max_num_links(t_file** files) {
    t_file *file = *files;
    int max_lenght = 0;
    while(file) {
        int len = mx_strlen(file->num_links);
        if(len > max_lenght) {
            max_lenght = len;
        }
        file = file->next;
    }
    return max_lenght;
}

