//
// Created by Rahul on 6/18/2019.
//
#include <stdio.h>
int main()
{
    int c;
    while((c=getchar())!=EOF)
    {
        if(c=='\t')
            printf("\\t");
        if(c=='\b')
            printf("\\b");
        if(c=='\\')
            printf("\\\\");
        if(c!='\b')
            if(c!='\t')
                if(c!='\\')
                    putchar(c);
 /* if(c=='\t')  // Another Way 
		{
			putchar('\\');
			putchar('t');
		}
		else if(c=='\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if(c=='\\')
		{
			putchar('\\');
			putchar('\\');
		}
		else 
		{
			putchar(c);
		}
 */
    }
}