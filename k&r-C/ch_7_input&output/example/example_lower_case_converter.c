//
// Created by rahul on 21/7/19.
//
#include <stdio.h>
#include <ctype.h>
main()
{
    int c;
    while((c=getchar())!=EOF)
        putchar(tolower(c));
    return 0;
}