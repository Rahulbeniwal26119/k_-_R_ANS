//
// Created by rahul on 21/7/19.
//
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100 //maximum number of char in one line
#define OCTLEN 6 //length of an octal value
//print arbitary input in a sensible way
int main()
{
    int c,pos;
    int inc(int pos,int n);
    pos=0;
    while((c=getchar())!=EOF)
        if(iscntrl(c) || c==' ')//non graphic or blanks
        {
            pos=inc(pos,OCTLEN);
            printf("\\%03o",c);
            if(c=='\n')
            {
            pos=0;
            putchar('\n');
        }
            }
    else
        {
        pos=inc(pos,1);
        putchar(c);
        }
}
/*inc :: increment position counter for position*/
int inc(int pos,int n)
{
    if(pos+n<MAXLINE)
        return pos+n;
    else
    {
        putchar('/n');
        return n;
    }

}
