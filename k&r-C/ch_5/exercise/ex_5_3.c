#include<stdio.h>
#include<stddef.h>
void  strcat(char *p , char *s)
{
  while(*++p);
  while(*p++ = *s++);
}
int main()
{
  char s1[20]="Rahul";
  char s2[10]="Beniwal";
  strcat(s1 , s2);
  printf("%s" , s1);
}
