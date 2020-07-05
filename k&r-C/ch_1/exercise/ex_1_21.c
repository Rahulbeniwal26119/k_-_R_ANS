#include<stdio.h>
#define TAB 8
int main()
{
    int c;
    int len=1;
    int nt=0; // number of tabs required 
    int nb=0; // number of blanks required
    while ((c=getchar())!=EOF)
    {
        if(c==' ')
        {
            if(len % TAB !=0)  // checking if len of line is divisible by 8 
            ++nb;
            else  // if we found a such of position then tab will cover all blanks 
            {
                nb=0;
                ++nt;
            }
        }
        else
        {
            for(;nt>0;--nt)
            putchar('\t');
            if(c=='\t')
            {
                nb=0;
            }
            else
            {
                for(;nb>0;--nb)
                putchar(' ');
            }
            putchar(c);
            if(c=='\n')
            len=0;
            else if(c=='\t')
                len=len+(TAB - (len-1) % TAB) -1;   // finding the new position after a tab 
        }
    }
}