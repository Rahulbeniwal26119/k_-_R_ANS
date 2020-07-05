#include<stdio.h>
#define TAB 8
int main()
{
    int c;
    int tabrequired;
    int len=0;
    while((c=getchar())!=EOF)
    {
        if(c=='\t')
        {
            tabrequired=TAB - (len) % TAB;
            while(tabrequired > 0)
            {
                putchar('*');
                --tabrequired;
                ++len;
            }
        }
        else if(c=='\n')
        {
            putchar(c);
            len=0;
        }
        else{
            putchar(c);
            ++len;
        }
    }
}