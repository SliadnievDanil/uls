#include "../inc/uls.h"

void get_lm_date(t_file **file, struct stat *info, t_flag *flags) {
    time_t cur_time;
    time(&cur_time);
    char *time_str = mx_strnew(100);
    mx_strcpy(time_str, ctime(&info->st_mtime));
    if(flags->u)
        mx_strcpy(time_str, ctime(&info->st_atime));
    if(flags->c)
        mx_strcpy(time_str, ctime(&info->st_ctime));
    char **lm = mx_strsplit(time_str, ' ');
    (*file)->lm_month = mx_strdup(lm[1]);
    (*file)->lm_day = mx_strdup(lm[2]);
    int temp = cur_time - info->st_mtime;
    if(flags->T) {
        (*file)->lm_time = mx_strndup(&time_str[11], 13);
    } else if(temp > 15552000|| (temp < 0 && temp > (-1 * 15552000))) {
        (*file)->lm_time = mx_strndup(lm[4], 4);
    } else {
        (*file)->lm_time = mx_strndup(lm[3], 5);
    }
    free(time_str);
    mx_del_strarr(&lm);
}

