#include<stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE]; //buffer for ungetch
int bufp; //next free position in buf
int getch(void) /* get a possibly pushed back character*/
{
  return (bufp>0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /*push charcter back to input*/
{
  if(bufp>=BUFSIZE)
  printf("error too many argument ");
  else
  buf[bufp++]=c;
}
