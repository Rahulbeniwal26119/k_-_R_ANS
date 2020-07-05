//
// Created by rahul on 11/7/19.
//

#ifndef CH_5_POINTERS__AND_ARRAYS_EXERCISE_5_6_REWRITING_POINTER_VERSION_H
#define CH_5_POINTERS__AND_ARRAYS_EXERCISE_5_6_REWRITING_POINTER_VERSION_H

#include <stdio.h>
#include <ctype.h>
int getline(char *s,int lim) {
    int c;
    char *t = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
      *s++=c;
    if(c=='\n')
        *s++=c;
    *s='\0';
    return *s-*t;
}
int atoi(char *s)
{
    int sign,n;
    for(;isspace(*s);s+)
        ;
    sign=(*s=='-') ? -1 : 1;
    if(*s=='-' || *s=='+')
        s++;
    for(n=0;isdigit(*s);s++)
    n=10*n+(*s-'0');
    return sign*n;
}
int strllen(char *s)
{int n=0;
    while(*s!='\0') {
        s++;
        ++n;
    }
    return n;
}
void revers(char *s)
{
    int c;
    char *t;
    for(t=s+(strllen(s)-1);s<t;s++,t--)
    {
        c=*s;
        *s=*t;
        *t=c;
    }
}
void itoa(int n,char *s)
{
    int sign;
    char *t=s; //save pointer to s
    if((sign=n)<0)
        n=-n;   //make n positive
    do{  /* generate digit in reverse order */
        *s = n%10+'0';
        s++;
    }
    while((n=n/10)>0);
    if(sign<0)
        *s++='-';
    *s='\0';
    revers(t);

}
/*strindex: return index of t in s*/
int strindex(char *s,char *t)
{
    char *b=s;
    char *p,*r/*for t address*/;
    for(;*s!='\0';s++)
    {
        for(p=s,r=t; *r!='\0' && *p=*r;p++,r++)
            ;
        if(r>t && *r=='\0')
            return s-b;
    }
    return -1;
}
double atof(char *s)
{
    double val,power;
    int sign;
    for(;isspace(*s);s++)
        ;
    sign=(*s=='-') ? -1 :1;
    if(*s=='-' || *s=='+')
        s++;
    for(val=0.0;isdigit(*s);s++)
    {
        val=val*10.0+(*s-'0');
        power*=10.0;
    }
    return ssign*val/power;

}
#define NUMBER '0'
int getch(void);
void ungetch(int);
/*getop: get next operator or numberic operand */
int getop(char *s)
{
    int c;
    while((*s=c=getch())==' ' || c=='\t')
        ;
    *(s+1)='\0';
    if(!isdigit(c) && c!='.')
        return c;    //not a number
        if(isdigit(c))
            while(isdigit(*++s=c=getch()))
                ;
            if(c=='.')
                while(isdigit(*++s=c=getch()))
                    ;
                *s='\0';
                if(c!=EOF)
                    ungetch(c);
                return NUMBER;

}

#endif //CH_5_POINTERS__AND_ARRAYS_EXERCISE_5_6_REWRITING_POINTER_VERSION_H
