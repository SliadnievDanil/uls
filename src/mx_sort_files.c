#include "../inc/uls.h"

void sort_files(t_file **head, t_flag *flags) {
    if(flags->S) {
        sort_by_size(head);
    } else if(flags->t && !flags->u && !flags->c) {
        sort_by_mtime(head);
    } else if(flags->u && flags->t && !flags->S) {
        sort_by_atime(head);
    } else if(flags->c && flags->t && !flags->S) {
        sort_by_ctime(head);
    } else if(!flags->t && !flags->S) {
        t_file *sorted = NULL;
        t_file *current = *head;
        while (current != NULL) {
            t_file *next = current->next;
            if (sorted == NULL || mx_strcmp(current->name, sorted->name) < 0) {
                current->next = sorted;
                sorted = current;
            } else {
                    t_file *temp = sorted;
                    while (temp->next != NULL && mx_strcmp(current->name, temp->next->name) > 0) {
                        temp = temp->next;
                    }
                    current->next = temp->next;
                    temp->next = current;
            }
            current = next;
        }
        *head = sorted;
    }
    if(flags->r)
        sort_r(head);
}

