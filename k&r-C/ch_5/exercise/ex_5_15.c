// all required functions are in exercise 5_14
#include "ex_5_14.c"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define LINES 100
int charcmp(char * , char *);
// int numcmp(char * , char *);
// int readlines(char *lineptr , char maxlines);
// void qqsort(char *v[] , int left , int right  , int (*comp)(void* , void *));
// void writelines(char  *lineptr[] , int nlines , int order);
int main(int argc , char *argv[])
{
  int nlines;
  int c , rc=0;
  while(--argc > 0 && (*++argv)[0]=='-')
  while(c=*++argv[0])
  switch(c)
  {
    case 'f':
    option|=FOLD;
    break;
    case 'n':
    option|=NUMERIC;
    break;
    case 'r':
    option|=DECR;
    break;
    default:
    printf("illegal options %c\n" , c);
    argc=1;
    rc=-1;
    break;
  }
  if(argc)
  printf("Usage : sort -fnr \n");
  else
  {
    if((nlines=readlines(lineptr , LINES ))>0){
    if(option & NUMERIC)
    qqsort((void**)lineptr , 0 , nlines-1 , (int (*)(void * , void *)) numcmp);
    else if(option & FOLD)
    qqsort((void **)lineptr , 0 , nlines-1 , (int (*)(void * , void *))  charcmp);
    else
    qqsort((void **)lineptr , 0 , nlines -1  , (int (*)(void * , void *)) strcmp );
    writelines(lineptr , nlines , option & DECR);
  }
  else
  {
    printf("input too big to sort\n");
    rc=-1;
  }
}
return rc;
}
int charcmp(char *s1 , char *s2)
{
  // printf("in charcmp");
  for(;tolower(*s1)==tolower(*s2) ; s1++ , s2++);
  // printf("in for ");
  if(*s1=='\0')
  return 0;
  else
  return tolower(*s1) - tolower(*s2);
}
