#include<stdio.h>
#include<ctype.h>
#define NUMERIC 1
#define DECR 2
#define  FOLD 4
#define DIR 8
#define LINES 100
int charcmp(char * , char *);
int numcmp(char * , char *)';
int readlines(char *v[] , int maxlines);
void  qqsort((void)**v , int left , int right , int (*comp)(void *, void *));
void writelines(char *v[] , int nlines , int option);\
static char option=0;
int main(int argc , char **argv)
{
  int nlines;
  int c ;
  while( --argc > 0 && (*++argv)[0]=='-')
  while(c=*++argv[0])
  switch(c)
  {
    case 'd':
    option|=DIR;
    break;
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
    printf("sort : illegal option %c\n" , c);
    argc=1;
    break;
  }
  if(argc)
  printf("Usage : sort -dfnr\n");
  else
  {
    if((nlines=readlines(lineptr , LINES))>0)
    {
      if(option&NUMERIC)
      qqsort((void **)lineprt , 0 , nlines-1 , (int (*)(void * , void *))numcmp);
      else
      qqsort((void **)lineptr ,  0 , nlines-1 ,, (int (*)(void * , void *))charcmp);
      writelines(lineptr , nlines , option & DECR);
    }
    else
    {
      printf("input too big to sort\n");
    }
  }
}
int charcmp(char *s1 , char *s2)
{
  char a , b;
  int fold = option & FOLD;
  int dir = option & DIR;
  do
  {
    if(dir)
    {
    while(!isalnum(*s) && *s!=' ' && *s!='\0')
    s++;
    while(!isalnum(*t) && *t!=' ' && *t!='\0')
    t++;
  }
  a=fold ? tolower(*s) : *s;
  s++;
  b=fold ? tolower(*t) : *t;
  t++;
  if(a==b && a=='\0')
  return 0;
}
  while(a==b);
  return a - b;
}
