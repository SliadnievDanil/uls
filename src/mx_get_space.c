#include "../inc/uls.h"

void get_space(t_file **files, t_lenghts *lenghts) {
    t_file *file = *files;
    while(file) {
    file->num_links = set_front_space(file->num_links, lenghts->lenght_num_links);
    file->size = set_front_space(file->size, lenghts->lenght_size);
    file->lm_day = set_front_space(file->lm_day, lenghts->lenght_day);
    file->lm_time = set_front_space(file->lm_time, lenghts->lenght_time);
    file->user_name = set_back_space(file->user_name, lenghts->lenght_user_name);
    file->group_name = set_back_space(file->group_name, lenghts->lenght_gr_name);
    file = file->next;
    }
}

