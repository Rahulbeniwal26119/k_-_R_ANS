#include <stdio.h>
#define TABINC 8 //tab increment size
int main()
{
    int c, nb, pos;
    nb = 0;
    pos = 0; // no character is input till now so position is zero
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            nb = TABINC - (pos) % TABINC;
            while(nb > 0)
                {
               putchar(' ');
               ++pos;
               --nb;
                }
                
        }
        else if(c == '\n')
        {
            pos=0;
        }
        else
        {
            putchar(c);
            ++pos;
        }
    }
}