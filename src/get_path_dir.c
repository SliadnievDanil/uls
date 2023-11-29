#include "../inc/uls.h"

char *get_path_dir(char *dir, char* file) {
    char *path = mx_strnew(mx_strlen(dir) + mx_strlen(file) + 1);
    mx_strcpy(path, dir);
    mx_strcat(path, "/");
    mx_strcat(path, file);
    return path;
}

