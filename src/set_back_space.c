#include "../inc/uls.h"

char *set_back_space(char *str, int max_lenght) {
    int lenght = mx_strlen(str);
    if(lenght == max_lenght) {
        return str;
    }
    char *new = (char*) malloc((max_lenght + 1) * sizeof(char));
    mx_strcpy(new, str);
    for(int i = lenght; i < max_lenght; i++) {
        new[i] = ' ';
    }
    return new;
}

