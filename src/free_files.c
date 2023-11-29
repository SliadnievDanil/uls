#include "../inc/uls.h"

void free_files(t_file *head) {
    t_file *current = head;
    while (current != NULL) {
        t_file *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
}

