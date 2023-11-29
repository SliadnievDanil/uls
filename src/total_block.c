#include "../inc/uls.h"

int total_block(t_file **files) {
    int total = 0;
    t_file *file = *files;
    while(file) {
        if(stat(file->path, &file->info) != -1)
            total += file->info.st_blocks;
        file = file->next;
    }
    return total;
}

