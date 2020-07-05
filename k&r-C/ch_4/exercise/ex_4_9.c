int bufp=0;
#include<stdio.h>
#define BUFSIZE 100
int buf[BUFSIZE];
int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch : too many characters\n");
    else
        buf[bufp++] = c;
}
/*
The hack of this problem is to use only 
int array instead of character 
As EOF is -1 and int array can easily handle it 

negative number ( - 1) -> character ->  Interger 
OxFFFF                      OxFF            Ox00FF (255)
OxFFFF                      OxFF            OxFFFF ( - 1)

These Two cases are possible
so integer increase portability
and if it is integer array no conversion will happen*/
