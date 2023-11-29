#include "../inc/uls.h"

void info_lenght(t_file **files) {
    t_lenghts *lenghts = fill_lenghts(files);
    get_space(files, lenghts);
    free(lenghts);
}

t_lenghts *fill_lenghts(t_file** files) {
    t_lenghts *lenghts = malloc(sizeof(t_lenghts));
    lenghts->lenght_num_links = get_max_num_links(files);
    lenghts->lenght_size = get_max_size(files);
    lenghts->lenght_gr_name = get_max_gr_name(files);
    lenghts->lenght_user_name = get_max_user_name(files);
    lenghts->lenght_day = get_max_day(files);
    lenghts->lenght_time = get_max_time(files);
    return lenghts;
}

