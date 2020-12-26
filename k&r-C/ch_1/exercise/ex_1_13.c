
#include<stdio.h>
#define IN 1
#define OUT 0
#define MAXWORD 11
#define MAXHIST 15  // Only need for vertical drawing as maximum height is a needed constraint there
int main()
{
    int wl[MAXWORD];
   int  state = OUT;
    for(int i=1;i<MAXWORD;i++)
    wl[MAXWORD] = 0;
    int nc=0;
    int c;
    int overflow = 0;

    for(int i=1; i<MAXWORD; ++i)
    {
        wl[i]=0;
    }
    while((c=getchar())!=EOF)
    {
        if(c==' ' || c=='\t' || c=='\n')
            {
                state = OUT;
                if(nc < MAXWORD)
                    wl[nc]++;
                else 
                    ++overflow;
                nc=0;
            }
            else if(state==OUT)
            {
                state = IN;
                nc=1;
            }
            else 
            {
                nc++;
            }
    }
    int max_length_word = 0;
    for(int i=1; i<MAXWORD; ++i)
    {
        int len = wl[i];
        if(len > max_length_word)
            max_length_word = len;
        printf("%d\t%d\t" , i , len);
        while(len > 0)
        {
            putchar('*');
            len--;
        }
        printf("\n");
    }
    printf("\n There are  %d over flow words\n" , overflow);

    // Vertical Histograph 
    // for(int i=MAXHIST; i>0; --i)
    // {
    //     for(int j=1; j<MAXWORD; ++j)
    //     {
    //         if(wl[j] * MAXHIST / max_length_word >= i)
    //             printf(" * ");
    //         else 
    //           printf("   ");
    //     }
    //     putchar('\n');
    // }
}