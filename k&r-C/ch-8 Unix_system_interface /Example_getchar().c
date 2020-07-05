//
// Created by rahul on 28/7/19.
//
#include <unistd.h>
#include <stdio.h>

int getchar(void)
{
    char c;
    return (read(0,&c,1)==1) ?  (unsigned char) c: EOF;
}
int main() {
    int c;
    c = getchar();
}
//working