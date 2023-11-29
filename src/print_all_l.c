#include "../inc/uls.h"

void print_all_l(char **argv, t_flag *flags, int argc) {
    t_file *files_head = NULL;
    t_file *dirs_head = NULL;
    int file_index = 0;
    int dir_index = 0;
    int file_count = 0;
    int directory_count = 0;
    int num_words = argc-1;
    char **list = (char **)malloc(num_words * sizeof(char *));
    for(int i = 0; i < num_words; i++) {
        list[i] = (char *)malloc((mx_strlen(argv[i+1]) + 100) * sizeof(char));
    }
    int check = 0;
    for (int i = 2; i < argc; i++) {
        struct stat st;
        if (lstat(argv[i], &st) == 0) {

            if (stat(argv[i], &st) == 0 && S_ISREG(st.st_mode)) {
                file_count++;
                add_file(&files_head, argv[i], file_index, flags, NULL);
                file_index++;
            }
            else {
                directory_count++;
                add_file(&dirs_head, argv[i], dir_index, flags, NULL);
                dir_index++;
            }
        } else {
            if(argv[i][0] == '-' && mx_strlen(argv[i]) > 1 && dir_index == 0) {

            } else {
            mx_strcpy(list[check], argv[i]);
            flags->error = 1;
            check++;
            }
        }
    }
    if(flags->error == 1) {
        sort_err(list, check);
        for(int i = 0; i < check; i++) {
            if(list[i] != NULL)
                print_dir_err(strerror(errno), list[i]);
        }
    }
    if(file_count != 0) {
        sort_files(&files_head, flags);
        info_lenght(&files_head);
        while(files_head != NULL) {
        if (lstat(files_head->name, &files_head->info) != -1) {
            printFileInfo(files_head, flags);
        }
        files_head = files_head->next;
        }
    }
    if(directory_count != 0 && file_count > 0) {
        mx_printchar('\n');
        sort_files(&dirs_head, flags);
    }
    print_dir_l(dirs_head, file_count, directory_count, flags);
}

