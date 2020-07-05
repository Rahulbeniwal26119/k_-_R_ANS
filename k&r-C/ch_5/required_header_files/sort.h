//
// Created by rahul on 11/7/19.
//

#ifndef CH_5_POINTERS__AND_ARRAYS_SORT_H
#define CH_5_POINTERS__AND_ARRAYS_SORT_H

#include <stdio.h>
#include "getch_ungretch.h"
#define MAXLEN 1000/*maximum length of any input lines */
int getline(char *,int );
char *alloc(int);
int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p,line[MAXLEN];
    while((len=getline(line,MAXLEN))>0)
        if(nlines>=maxlines || (p=alloc(len))==NULL)
            return -1;
        else
        {
            line[len-1]='\0'; //deleate newlines
            strncpy(p,line);
            lineptr[nlines++]=p;
        }
        return nlines;
}
void writelines(char *lineptr[],int nlines)
{
    int i;
    for(i=0;i<nlines;i++)
        printf("%s\n",lineptr[i]);
}
void qsort(char *v[],int left,int right )
{
    int i,last;
    void swap(char *v[],int i,int j);
    if(left>=right)
        return ; //fewer than 2 element
        swap(v,left,(left+right)/2);
        last=left;
        for(i=left+1;i<=right;i++)
        if(strncmp(v[i],v[left])<0)
            swap(v,++last,i);
        swap(v,left,last);
        qsort(v,left,last-1);
        qsort(v,last+1,right);

}
#endif //CH_5_POINTERS__AND_ARRAYS_SORT_H
