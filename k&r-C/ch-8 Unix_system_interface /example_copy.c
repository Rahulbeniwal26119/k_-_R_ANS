//
// Created by rahul on 28/7/19.
//
#include <unistd.h>
#include <stdio.h>
#define BUFIZE 1000

int main()
{
    int c;
    char buffer[BUFIZE];
        while((c=read(0,buffer,BUFIZE))>0)
            write(1,buffer,c);
        return 0;

}