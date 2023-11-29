#include "../inc/uls.h"

char *set_front_space(char *str, int max_lenght) {
    int lenght = mx_strlen(str);
    if(lenght == max_lenght) {
        return str;
    }
    char *new = (char*) malloc((max_lenght + 1) * sizeof(char));
    int space = max_lenght - lenght;
    for(int i = 0; i < space; i++) {
        new[i] = ' ';
    }
    mx_strcpy(&new[space], str);
    return new;
}

