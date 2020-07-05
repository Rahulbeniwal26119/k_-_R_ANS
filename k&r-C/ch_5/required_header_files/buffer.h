//
// Created by rahul on 10/7/19.
//

#ifndef CH_5_POINTERS__AND_ARRAYS_BUFFER_H
#define CH_5_POINTERS__AND_ARRAYS_BUFFER_H

#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE]; /*buffer for ungetch*/
int bufp=0; //next free position in buf
int getch(void)  //get a (possibaly) pushed back character
{
    return (bufp>0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /*push charcter back on input */
{
    if(bufp>=BUFSIZE)
        printf("ungrtch too many charcter");
    else
        buf[bufp++]=c;
}
#endif //CH_5_POINTERS__AND_ARRAYS_BUFFER_H
