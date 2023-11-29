#include "../inc/uls.h"

void sort_by_atime(t_file **head) {
    t_file *sorted = NULL;
    t_file *current = *head;
    while (current != NULL) {
        t_file *next = current->next;
        if (sorted == NULL || current->info.st_atime > sorted->info.st_atime) {
            current->next = sorted;
            sorted = current;
        } else {
            t_file *temp = sorted;
            while (temp->next != NULL && current->info.st_atime <= temp->next->info.st_atime) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }
    *head = sorted;
}

