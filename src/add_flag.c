#include "../inc/uls.h"

void add_flag(t_flag** flags, char flag) {
    switch(flag) {
        case 'l':
            (*flags)->l = 1;
            (*flags)->count++;
            break;
        case 'R':
            (*flags)->R = 1;
            (*flags)->count++;
            break;
        case 'C':
            (*flags)->C = 1;
            (*flags)->one = 0;
            (*flags)->count++;
            break;
        case '1':
            (*flags)->one = 1;
            (*flags)->C = 0;
            (*flags)->count++;
            break;
        case 'A':
            (*flags)->A = 1;
            (*flags)->count++;
            break;
        case 'a':
            (*flags)->a = 1;
            (*flags)->count++;
            break;
        case 'G':
            (*flags)->G = 1;
            (*flags)->count++;
            break;
        case 'e':
            (*flags)->e = 1;
            (*flags)->count++;
            break;
        case 'T':
            (*flags)->T = 1;
            (*flags)->count++;
            break;
        case '@':
            (*flags)->at = 1;
            (*flags)->count++;
            break;
        case 'r':
            (*flags)->r = 1;
            (*flags)->count++;
            break;
        case 'u':
            (*flags)->u = 1;
            (*flags)->c = 0;
            (*flags)->count++;
            break;
        case 'c':
            (*flags)->c = 1;
            (*flags)->u = 0;
            (*flags)->count++;
            break;
        case 'S':
            (*flags)->S = 1;
            (*flags)->count++;
            break;
        case 't':
            (*flags)->t = 1;
            (*flags)->count++;
            break;
        default:
            break;
    }
}

