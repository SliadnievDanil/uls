#include "../inc/uls.h"

char *get_acl_text(t_file *file, t_flag *flags) {
    acl_t acl = acl_get_file(file->path, ACL_TYPE_EXTENDED);
    if(flags->e) {
        file->acl_str = acl_to_text(acl, NULL);
        acl_free(acl);
        return file->acl_str;
    } else {
        return NULL;
    }
}

