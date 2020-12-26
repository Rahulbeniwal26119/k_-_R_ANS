#include<stdio.h>
#define IN 1
#define OUT 0
int main()
{
	int c;
	int state = OUT;
	while((c=getchar())!=EOF)
	{
		if(state==OUT)
		{
			putchar(c);
			if(c==' ')
				state=IN;
		}
		else if(state==IN && c!=' ')
		{
			putchar(c);
			state=OUT;
		}

	}
}
