#include<stdio.h>
#include<ctype.h>
#define MAXLINE 100
#define OCTLEN 6  //length of an octal values
int main()
{
  int c;
  while((c=getchar())!=EOF)
  {
    if(iscntrl(c) || c==' ')
    {
      pos = inc(c , OCTLEN);
      printf("\\%03o" , c);
      if(c=='\n'){
        pos=0;
        putchar('\n');
    }
    else
    {
      pos = inc(pos , 1);
      putchar(c);
    }
  }
  int inc(int pos , int n)
  {
    if(pos + n < MAXLINE)
    return pos + n;
    else
    {
      putchar('\n');
      return n;
    }

  }
