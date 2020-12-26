#include<stdio.h>
#define TABSIZE 8

int main()
{
    int c, nb , nt , pos;
    nb=0 , nt=0;
    for(pos=1; (c=getchar())!=EOF; ++pos)
    {
        if(c==' ')
        {
            if(pos%TABSIZE !=0)
                ++nb;
            else 
            {
                nt++;
                nb=0;
            }
        }
        else 
        {
            for(; nt > 0; --nt)
            putchar('\t');
            if(c=='\t')
                nb = 0;
            else 
            {
                for(;nb>0;--nb)
                {
                    putchar(' ');
                }
            }
            putchar(c);
            if(c=='\n')
                pos=0;
            else if(c=='\t')
                pos=pos + (TABSIZE - (pos) % TABSIZE);
        }
    }
}