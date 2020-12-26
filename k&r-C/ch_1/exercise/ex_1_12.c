#include<stdio.h>
#define IN 1
#define OUT 0
int main()
{
int c , state=OUT;
int wc=0;
int test;
while((c=getchar())!=EOF)
{
	test=c==' ' || c=='\t' || c=='\n';
	if(!test)
	{
		state=IN;
		putchar(c);
	}
	else if(test && state==IN)
	{
		state=OUT;
		putchar('\n');
		wc++;
	}
}
printf("\n%d" , wc);
}

