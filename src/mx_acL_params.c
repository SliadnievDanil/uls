#include "../inc/uls.h"

void acL_params(char **params, int i) {
    mx_printchar(' ');
    mx_printint(i);
    mx_printstr(": ");
    mx_printstr(params[0]);
    mx_printstr(":");
    mx_printstr(params[2]);
    mx_printchar(' ');
    mx_printstr(params[4]);
    mx_printchar(' ');
    mx_printstr(params[5]);
    mx_printchar('\n');
}

