#include "../inc/uls.h"

void output_acl(const char* acl) {
    char **acl_l = mx_strsplit(acl, '\n');
    for(int i = 1; acl_l[i] != NULL; ++i) {
        char **params = mx_strsplit(acl_l[i], ':');
        acL_params(params, i-1);
        mx_del_strarr(&params);
    }
    mx_del_strarr(&acl_l);
}

