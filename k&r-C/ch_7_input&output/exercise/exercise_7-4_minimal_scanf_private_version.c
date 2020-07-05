//
// Created by rahul on 24/7/19.
//
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#define LOCALFMT 100
void minscanf(char *fmt,...)
{
    va_list ap; //point to each unnamed argument
    char *p,*sval;
    char localfmt[LOCALFMT];
    int c,i,*ival;
    unsigned *uval;
    double *dval;
    i=0;
    va_start(ap,fmt);
    for(p=fmt;*p;p++) {
        if ((*p != '%')& !isalpha(*(p+1)))
        localfmt[i++]=*(p+1);
        localfmt[i]='\0';
        switch(*++p)
        {
            case 'd':
            case 'i':
                ival=va_arg(ap,int *);
                scanf(localfmt,ival);
                break;
            case 'x':
            case 'X':
            case 'u':
            case'o':
                uval=va_arg(ap,unsigned *);
                break;
            case 'f':
                dval=va_arg(ap,double *);
                scanf(localfmt,dval);
                break;
            case 's':
                sval=va_arg(ap,char *);
                scanf(localfmt,sval);
                break;
            default:
                scanf(localfmt);
                break;
        }

    }

}
