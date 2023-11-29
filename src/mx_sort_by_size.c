#include "../inc/uls.h"

void sort_by_size(t_file **head) {
    t_file *sorted = NULL;
    t_file *current = *head;
    while (current != NULL) {
        t_file *next = current->next;
        if (sorted == NULL || current->info.st_size > sorted->info.st_size) {
            current->next = sorted;
            sorted = current;
        } else {
            t_file *temp = sorted;
            while (temp->next != NULL && current->info.st_size <= temp->next->info.st_size) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }
    *head = sorted;
}

