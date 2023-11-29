#include "../inc/uls.h"

int get_file_count(t_file *head) {
    int count = 0;
    t_file *current = head;
    while(current->next != NULL && current->name != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

