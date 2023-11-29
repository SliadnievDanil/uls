#include "../inc/uls.h"

void print_dir_err(char *error, char *path) {
    mx_printerr("uls: ");
    mx_printerr(path);
    mx_printerr(": ");
    mx_printerr(error);
    mx_printerr("\n");
}

