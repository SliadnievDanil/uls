#include "../inc/uls.h"

void print_dir_l(t_file *head, int file_count, int directory_count, t_flag *flags) {
    DIR *dir;
    struct dirent *de;
    t_file *current = head;
    sort_files(&current, flags);
    while (current != NULL) {
        if(directory_count != 1 || file_count > 0 || flags->error == -1) {
            mx_printstr(current->name);
            mx_printstr(":\n");
        }
        int total_blocks = 0;
        mx_printstr("total ");
        dir = opendir(current->name);
        t_file *dir_files = NULL;
        int index = 0;
        while ((de = readdir(dir)) != NULL) {
            if(mx_strcmp(de->d_name, ".") == 0 
                || mx_strcmp(de->d_name, "..") == 0
                || de->d_name[0] == '.') {
                continue;
            }
            char *path = get_path_dir(current->name, de->d_name);
            add_file(&dir_files, de->d_name, index, flags, path);
            index++;
        }
        total_blocks = total_block(&dir_files);
        mx_printint(total_blocks);
        mx_printstr("\n");
        sort_files(&dir_files, flags);
        info_lenght(&dir_files);
        while(dir_files != NULL) {
            if (lstat(current->name, &dir_files->info) != -1) {
                printFileInfo(dir_files, flags);
            }
            dir_files = dir_files->next;
        }
        if(flags->R) {
            dir = opendir(current->name);
            //mx_printchar('\n');
            print_R(flags, dir, current->name, 0, 0, 0);
        }
        if(current->next != NULL)
            mx_printchar('\n');
        current = current->next;
    }
}

