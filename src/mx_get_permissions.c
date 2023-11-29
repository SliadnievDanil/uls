#include "../inc/uls.h"

char *get_permissions(struct stat *info) {
    mode_t mode = info->st_mode;
    char *permissions = mx_strnew(10);
    int i = 0;
    permissions[i++] = *(IS_DIR(mode));
    permissions[i++] = *(IS_RUSR(mode));
    permissions[i++] = *(IS_WUSR(mode));
    permissions[i++] = *(IS_XUSR(mode));
    permissions[i++] = *(IS_RGRP(mode));
    permissions[i++] = *(IS_WGRP(mode));
    permissions[i++] = *(IS_XGRP(mode));
    permissions[i++] = *(IS_ROTH(mode));
    permissions[i++] = *(IS_WOTH(mode));
    permissions[i++] = *(IS_XOTH(mode));
    return permissions;
}

