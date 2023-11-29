#include "../inc/uls.h"

void full_list(t_file **head, t_flag *flags, DIR *dir) {
    struct dirent *entry;
    if(dir == NULL)
        dir = opendir(".");
    int index = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (mx_strcmp(entry->d_name, ".") == 0 
            || mx_strcmp(entry->d_name, "..") == 0
            || entry->d_name[0] == '.') {
                continue;
        }
        char *path = entry->d_name;
        add_file(head, path, index, flags, NULL);
        index++;
    }
    closedir(dir);
}

