//
// Created by Rahul on 6/18/2019.
//
#include <stdio.h>
int main()
/*count newline,character,tab*/
{
    int c,nb/*number of blanck*/,nt,nl;
    nb=nt=nl=0;
    while((c=getchar())!=EOF) {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }
    printf("%d %d %d ",nb,nt,nl);
}
