#include "../inc/uls.h"

void print_R(t_flag *flags, DIR *dir, char *path, bool first, bool end, int num) {
    int is_terminal = isatty(STDOUT_FILENO);
    int count = 0;
    if(dir == NULL || first == 1) {
        t_file *head = NULL;
        int d_count = 0;

        full_list(&head, flags, dir);
        sort_files(&head, flags);
        if(head)
            count = get_file_count(head);
        if(num > 1 || end != 1) {
            mx_printstr(path);
            mx_printstr(":\n");
        }
        if(flags->l != 1)
            print_files(head, is_terminal, flags);
        if(flags->l == 1) {
            print_current_l(flags, dir, path);
        }
        //free_files(head);
        t_file *direct = NULL;
        full_list_dir(&direct, flags, dir, path);
        if(direct != NULL) {
            sort_files(&direct, flags);
            d_count = get_file_count(direct);
        }
        if(d_count != 0) {
            if(flags->l != 1)
                print_directories(direct, is_terminal, count, d_count, flags);
            if(flags->l == 1) {
                print_dir_l(direct, count, d_count, flags);
            }
        }
        if(end != 1 && !flags->l) {
            mx_printchar('\n');
        }
    } else {
        t_file *direct = NULL;
        full_list_dir(&direct, flags, dir, path);
        int d_count = 0;
        if(direct != NULL) {
            d_count = get_file_count(direct);
            sort_files(&direct, flags);
        }
        if(d_count != 0) {
            print_directories(direct, is_terminal, count, d_count, flags);
        }
    }
}

