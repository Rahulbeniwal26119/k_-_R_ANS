#include<stdio.h>
#define MAXLINE 1000
int  getLine(char line[] , int maxline);
void copy(char to[] , char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max=0;
	while((len=getLine(line , MAXLINE))>0)
	{
	
		 printf("%s" , line);
	}
}

int getLine(char s[] , int lim)
{
	int c , i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
	{
		s[i]=c;	
	}
	--i;
	while(s[i]=='\t' || s[i]==' ')
		--i;
	if(i>=0)
	{
		i++;
		s[i]='\0';
	}
	else 
	{
		s[0]='\0';
		i=0; 
	}
	return i;
}
void copy(char to[] , char from[])
{
	int i=0;
	while((to[i] = from[i])!='\0')
		i++;
}
