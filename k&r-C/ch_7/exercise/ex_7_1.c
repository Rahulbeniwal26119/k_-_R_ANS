#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(int argc , char *argv[])
{
  int c;
  ++argv[0]; // by passing .
  ++argv[0]; // by passing /
  printf("%s" , argv[0]);
  if(strcmp(argv[0] , "lower")==0)
    while((c=getchar())!=EOF)
      putchar(tolower(c));
  else if(strcmp(argv[0] , "upper")==0)
      while((c=getchar())!=EOF)
        putchar(toupper(c));
   else
      while((c=getchar())!=EOF)
        putchar(c);
  return 0;
}
