#include "../inc/uls.h"

void sort_r(t_file **head) {
    t_file *prev = NULL;
    t_file *current = *head;
    t_file *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

