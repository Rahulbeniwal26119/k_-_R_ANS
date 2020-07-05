#include <stdio.h>

//
// Created by rahul on 25/7/19.
//
int getline(char *line,int max)
{
    if((fgets(line,max,stdin))==NULL)
        return 0;
    else
        return strlen(line);
}
