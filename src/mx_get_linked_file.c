#include "../inc/uls.h"

char* get_linked_file(t_file *file) {
    int size = file->info.st_size;
    char *res = mx_strnew(size);
    int link = readlink(file->path, res, size);
    if(link == -1) {
        mx_strdel(&res);
        return NULL;
    }
    res[link] = '\0';
    return res;
}

