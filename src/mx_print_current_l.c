#include "../inc/uls.h"

void print_current_l(t_flag *flags, DIR *dir, char *half) {
    if(dir == NULL)
        dir = opendir(".");
    struct dirent *entry;
    t_file *head = NULL;
    int index = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (mx_strcmp(entry->d_name, ".") == 0
            || mx_strcmp(entry->d_name, "..") == 0
            || entry->d_name[0] == '.') {
                continue;
        }
        char *path = entry->d_name;
        if(flags->R == 1) {
            if(half != NULL)
                path = get_path_dir(half, entry->d_name);
            add_file(&head, entry->d_name, index, flags, path);
            index++;
        } else {
        add_file(&head, path, index, flags, NULL);
        index++;
        }
    }
    int count = 0;
    if(head != NULL)
        count = get_file_count(head);
    t_file *current = head;
    if(count > 0)
        sort_files(&current, flags);
    info_lenght(&current);
    mx_printstr("total ");
    int total = 0;
    total = total_block(&current);
    mx_printint(total);
    mx_printchar('\n');
    while(current != NULL) {
        if (lstat(current->path, &head->info) != -1) {
            printFileInfo(current, flags);
        }
        current = current->next;
    }
}

