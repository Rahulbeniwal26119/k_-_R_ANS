#include<stdio.h>
#define MAXLINE 1000
int getlline(char line[] , int maxline)
{
    int c;
    int len=0;
    while((c=getchar())!=EOF && len < MAXLINE && c!='\n')
    {
        line[len]=c;
        ++len;
    }
    if(c=='\n')
    line[len]='\0';
    return len;
}
int main()
{
int len=0;
char line[MAXLINE];
while((len=getlline(line , MAXLINE)) > 0)
{
    if(len > 80)
    printf("%s\n" , line);
}
return 0;
}
