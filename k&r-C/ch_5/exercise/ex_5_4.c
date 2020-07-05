#include<stdio.h>
#include<string.h>
int  strend( char *s , char *p)
{
  int len1=0;
  len1=strlen(s);
  int len2=strlen(p);
  while(*s)
  s++;
  s=s-len2;
  while((*s++ == *p++) && *s);
  if(*s=='\0')
  return 1;
  else
  return 0;
}
int main()
{
  char a[]="Ram Krishna";
  char b[]="Krishna";
 printf("%d" , strend(a , b));
}
