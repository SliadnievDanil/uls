#include "../inc/uls.h"

void sort_by_mtime(t_file **head) {
    t_file *sorted = NULL;
    t_file *current = *head;
    while (current != NULL) {
        t_file *next = current->next;
        if (sorted == NULL || current->info.st_mtime > sorted->info.st_mtime) {
            current->next = sorted;
            sorted = current;
        } else {
            t_file *temp = sorted;
            while (temp->next != NULL && current->info.st_mtime <= temp->next->info.st_mtime) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }
    *head = sorted;
}

