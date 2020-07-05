//
// Created by rahul on 22/7/19.
//
#include <stdio.h>
#include <stdarg.h>
void miinprintf(char *fmt,...)
{
    va_list ap; //point to unname argument in turn
    char *p,*sval;
    int ival;
    double dval;
    va_start(ap,fmt);
    for(p=fmt;*p;p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap,arg);
                printf("%f",dval);
                break;
            case 's':
                for(sval=va_arg(ap,char *);*sval;sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;

        }
    }
}
