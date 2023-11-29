#include "../inc/uls.h"

void printFileInfo(t_file *filename, t_flag *flags) {
    mx_printstr(filename->perms);
    mx_printchar(get_extra_perms(filename));
    mx_printstr(" ");
    mx_printstr(filename->num_links);
    mx_printstr(" ");
    mx_printstr(filename->user_name);
    mx_printstr("  ");
    mx_printstr(filename->group_name);
    mx_printstr("  ");
    mx_printstr(filename->size);
    mx_printstr(" ");
    mx_printstr(filename->lm_month);
    mx_printstr(" ");
    mx_printstr(filename->lm_day);
    mx_printstr(" ");
    mx_printstr(filename->lm_time);
    mx_printstr(" ");
    mx_printstr(filename->name);
    if(filename->linked_file) {
        mx_printstr(" -> ");
        mx_printstr(filename->linked_file);
    }
    mx_printchar('\n');
    if(flags->at && listxattr(filename->path, NULL, 0, XATTR_NOFOLLOW) > 0) {
        output_xattr(filename->path);
    }
    if(flags->e && filename->acl_str != NULL) {
        output_acl(filename->acl_str);
    }
}

