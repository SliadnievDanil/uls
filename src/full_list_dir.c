#include "../inc/uls.h"

void full_list_dir(t_file **head, t_flag *flags, DIR *dir, char *half) {
    struct dirent *entry;
    if(dir == NULL) {
        dir = opendir(".");
    }
    int index = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (mx_strcmp(entry->d_name, ".") == 0 
            || mx_strcmp(entry->d_name, "..") == 0
            || entry->d_name[0] == '.') {
                continue;
        }
        struct stat st;
        char *path = entry->d_name;
        if(half != NULL)
            path = get_path_dir(half, entry->d_name);
        if(stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
        }
        else {
            add_file(head, path, index, flags, NULL);
            index++;
        }
    }
}

t_file* get_index_file(t_file* list, int index) {
    int i = 0;
    while(list) {
        if(i == index)
            return list;
        list = list->next;
        ++i;
    }
    return NULL;
}

