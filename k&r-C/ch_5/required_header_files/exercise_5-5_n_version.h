//
// Created by rahul on 11/7/19.
//

#ifndef CH_5_POINTERS__AND_ARRAYS_EXERCISE_5_5_N_VERSION_H
#define CH_5_POINTERS__AND_ARRAYS_EXERCISE_5_5_N_VERSION_H
void strncpy2(char *s,char *t,int n)
{
    while(*t && n-->0)
        *s++=*t++;
    while(n-->0)
        *s++='\0';
}
void strncat2(char *s,char *t,int n)
{
    void strncpy2(char *s,char *t,int n);
    int strlen(char *);
    strncpy2(s+strlen(s),t,n);
}
int strncmp2(char *s,char *t,int n)
{
    for(;*s==*t;++s,++t)
        if(*s!=='\0' || --n<=0)
            return 0;
        return *s-*t;
}
#endif //CH_5_POINTERS__AND_ARRAYS_EXERCISE_5_5_N_VERSION_H
