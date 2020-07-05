//
// Created by Rahul on 6/18/2019.
//
#include <stdio.h>
#define IN 1
#define OUT 0
/*prirnt one word per line*/
int main()
{
    int c,state;
    state=OUT;
    while((c=getchar())!=EOF)
    {
        if(c==' ' || c=='\n'||c=='\t') {
            if (state == OUT) {
                state=IN;
                putchar('\n');
            }
        }
            else if(state==IN)
            {
                putchar(c);
                state=OUT;
            }
            else
                putchar(c);
        }
}
