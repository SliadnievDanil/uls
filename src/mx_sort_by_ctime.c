#include "../inc/uls.h"

void sort_by_ctime(t_file **head) {
    t_file *sorted = NULL;
    t_file *current = *head;
    while (current != NULL) {
        t_file *next = current->next;
        if (sorted == NULL || current->info.st_ctime > sorted->info.st_ctime) {
            current->next = sorted;
            sorted = current;
        } else {
            t_file *temp = sorted;
            while (temp->next != NULL && current->info.st_ctime <= temp->next->info.st_ctime) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }
    *head = sorted;
}

