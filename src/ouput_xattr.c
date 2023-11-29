#include "../inc/uls.h"

void output_xattr(const char *path) {
    char namebuf[255];
    char tmp[255];
    int len = listxattr(path, namebuf, 255, XATTR_NOFOLLOW);
    int i = 0;
    int temp_len = 0;
    while(i < len) {
        mx_printchar('\t');
        mx_printstr(&namebuf[i]);
        temp_len = getxattr(path, &namebuf[i], tmp, 255, 0, 0);

        mx_printstr("\t   ");
        if(temp_len != -1) {
            mx_printint(temp_len);
        } else {
            mx_printint(0);
        }
        mx_printstr(" \n");
        i+= mx_strlen(&namebuf[i]) + 1;
    }
}

