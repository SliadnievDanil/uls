#include "../inc/uls.h"

void print_directories(t_file *head, int is_terminal, int file_count, int directory_count, t_flag *flags) {
    DIR *dir;
    struct dirent *de;
    t_file *current = head;
    if(file_count > 1)
        sort_files(&current, flags);
    int step = 0;
    while (current != NULL) {
        if(((directory_count != 1 || file_count > 0) || (directory_count == 1 && flags->error == 1))
            && flags->R != 1) {
            mx_printstr(current->name);
            mx_printstr(":\n");
        } else if(flags->R == 1) {
            mx_printstr("./");
            mx_printstr(current->name);
            mx_printstr(":\n");
        }
        dir = opendir(current->name);
        // Create a list of files for this directory
        t_file *dir_files = NULL;
        int index = 0;
        while ((de = readdir(dir)) != NULL) {
            if(mx_strcmp(de->d_name, ".") == 0 
                || mx_strcmp(de->d_name, "..") == 0
                || de->d_name[0] == '.'){
                continue;
            }
            if(flags->R == 1)
                add_file(&dir_files, de->d_name, index, flags, current->name);
            if(flags->R != 1)
                add_file(&dir_files, de->d_name, index, flags, NULL);
            index++;
        }
        // Sort the files in this directory
        sort_files(&dir_files, flags);
        // Print the files in this directory
        if(index > 0 && flags->l != 1)
            print_files(dir_files, is_terminal, flags);
        if(index > 0 && flags->l == 1 && flags->R == 1) {
            dir = opendir(current->path);
            print_current_l(flags, dir, current->path);
        }
        // Free the list of files for this directory
        free_files(dir_files);
        if(flags->R) {
            dir = opendir(current->name);
                mx_printchar('\n');
            print_R(flags, dir, current->name, 0, 0, 0);
            
        }
        step++;
        if (!is_terminal) {
            if(step != directory_count)
                mx_printstr("\n");
            }
        else {
            if(step != directory_count && flags->R != 1) {
                mx_printstr("\n");
            }
        }
        current = current->next;
    }
}

