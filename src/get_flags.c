#include "../inc/uls.h"

t_flag* get_flags(int argc, char **argv) {
    t_flag* flags = malloc(sizeof(t_flag));
    flags->error = 0;
    flags->count = 0;
    for(int i = 1; i < argc; i++) {
        if(argv[i][0] == '-' && mx_strlen(argv[i]) > 1) {
            for(int j = 1; argv[i][j] != '\0'; j++) {
                if(is_flag(argv[i][j])) {
                    add_flag(&flags, argv[i][j]);
                }
                else {
                    mx_printerr("uls: ");
                    mx_printerr("illegal option -- ");
                    mx_printerr(&argv[i][j]);
                    mx_printerr("\n");
                    mx_printerr("usage : uls [-lRC1AaGeT@rtucS] [file ...]\n");
                    exit(1);
                }
            }
        } else {
            break;
        }

    }
    return flags;
}

