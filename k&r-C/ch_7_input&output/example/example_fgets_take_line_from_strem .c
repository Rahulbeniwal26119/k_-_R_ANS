#include <bits/types/FILE.h>
#include <stdio.h>
//
// Created by rahul on 25/7/19.
//
//writing fgets and  fputs
char *fgets(char *s,int n,FILE *iop)
{
    register int c;
    register char *cs;
    cs=s;
    while(--n>0 && (c=getc(iop))!=EOF
    if((*cs++ =c) =='\n')
        break;
    *cs='\0';
    return (c==EOF && cs==s) ? NULL : s;
}
/*fputs : put string s file iop
 * /
 * */
int fputs(char *s, FILE *iop)
{
    int c;
    while(c==*s++)
        putc(c,iop);
    return ferror(iop) ? EOF : 0;
}
