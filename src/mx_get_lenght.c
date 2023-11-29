#include "../inc/uls.h"

int get_lenght(t_file *head) {
    int max_lenght = 0;
    t_file *current = head;
    while(current != NULL) {
        int len = mx_strlen(current->name);
        if(len > max_lenght) {
            max_lenght = len;
        }
        current = current->next;
    }
    return max_lenght;
}

