//
// Created by rahul on 24/7/19.
//

#include <stdio.h>
#include <ctype.h>
#define NUMBER '0'
int getop(char s[])
{
    int c,i,rc;
    static char lastc[]=" ";
    sscanf(lastc,"%c",&c);
    lastc[0]=' ';     //clear last chacarter
    while((s[0]=c)==' ' || c=='\t')
        if(scanf("%c",&c)==EOF)
            c=EOF;
        s[1]='\0';
        if(!isdigit(c) && c!='.')
            return c;
        i=0;
        if(isdigit(c))
            do{
                rc=scanf("%c",&c);
                if(!isdigit(s[++i]=c))
                    break;
            }while(rc!=EOF);
            if(c=='.')
                do{
                    rc=scanf("%c",&c);
                    if(!isdigit(s[++i]=c))
                        break;
                }while(rc!=EOF);
                s[i]='\0';
                if(rc!=EOF)
                    lastc[0]=c;
                return NUMBER;
}