#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSIZE_BUF 5000  //maximum storage for storing lines
char *lineptr[MAXLINES];
int getlline(char a[] , int len)
{
  int c;
  int i=0;
  while((c=getchar())!=EOF && c!='\n')
  a[i++]=c;
  if(c=='\n')
  a[i++]='\n';
  a[i]='\0';
  return i;
}
int readlines(char *lineptr[] , char *linestorage  , int maxlines)
{
  int len , nlines;
  char  line[MAXLEN];
  char *p= linestorage;
  char *linesfull = linestorage + MAXSIZE_BUF;  // indicate the last address of the buffer linestorage
  nlines=0;
  while((len=getlline(line , MAXLEN )) > 0)
  if(nlines > maxlines || p+len > linesfull)
  return -1;
  else
  {
    line[len -1 ] = '\0';
    strcpy(p , line );
    lineptr[nlines++]=p;
    p+=len;
  }
  return nlines;
}
void writelines(char *lineptr[] , int nlines)
{
  while(nlines-- > 0)
  printf("%s\n" , *lineptr++);
}
void swap(char *v[] , int i , int j)
{
  char *temp;
  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}
void qsort(char *v[] , int left , int right )
{
  int i,last;
  if(left >= right )
  return ;
  swap( v , left , (left+right)/2);
  last = left ;
  for(i=left+1 ; i<=right ; i++)
  if(strcmp(v[i] , v[left]) < 0)
  swap(v ,  ++last , i);
  swap(v , left , last);
  qsort( v , left , last-1);
  qsort(v , last+1 , right);
}
int main()
{
  int nlines;
  char linestorage[MAXSIZE_BUF];  // buffer work line malloc
  if((nlines=readlines(lineptr, linestorage , MAXLINES)) > 0)
  {
    qsort(lineptr , 0  , nlines-1);
    writelines(lineptr , nlines);
    return 0;
  }
  else
  {
    printf("Input too long to sort\n");
    return 1;
  }
}
