#include "../inc/uls.h"

char get_extra_perms(t_file *file) {
    ssize_t buf = listxattr(file->path, NULL, 0, XATTR_NOFOLLOW);
    acl_t acl = acl_get_file(file->path, ACL_TYPE_EXTENDED);
    if(buf > 0) {
        return '@';
    } else if(acl != NULL) {
        acl_free(acl);
        return '+';
    }
    return ' ';
}

