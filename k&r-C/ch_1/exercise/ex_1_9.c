//
// Created by Rahul on 6/18/2019.
//
#include <stdio.h>
#define NONBLANK '\65'
/* replaces string with many space with a  single space */
int main() {
    int c, lastc;
    lastc = NONBLANK;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
       if (c==' ' && lastc!=' ')          /* else if(lastc!=' ')  putchar(c)*/
            putchar(c);/* if(c!=' ' || lastc!=' ') putchar c; */
        lastc = c;
    }
}