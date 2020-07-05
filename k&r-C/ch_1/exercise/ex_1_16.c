//
// Created by Rahul on 6/19/2019.
//
#include <stdio.h>
#define MAXLINE 1000
int getine(char line[],int maxline);
void copy(char to[],char from[]);
int main()
{
int len;
int max;
char line[MAXLINE];
char longest[MAXLINE];
max=0;
while((len=getine(line,MAXLINE))>0)
    if(len>max){
        max=len;
        copy(longest,line);
	printf("%s:" , longest);
	printf("%d longest line length till now\n" , len);
    }
if(max>0)
    printf("%s",longest);
return 0;
}
int getine(char s[],int lim)
{
    int c;
    int i=0;
while((c=getchar())!=EOF && c!='\n')
{
s[i]=c;
i++;
}
s[i]='\0';
return i;

}
void copy(char to[],char from[])
{
    int i=0;
    while((to[i]=from[i])!='\0')
        ++i;
}
