//
// Created by rahul on 24/7/19.
//
#include <stdio.h>
int main()
{
    while(getline(line, sizeof(line))>0)
    {}
    if(sscanf(line,"%d %s %d",&day,monthname,&year)==3)
        printf("valid : %s\n",line);
    else if(sscanf(line,"%d%d%d",&month,&day,&year)==3)
        printf("VAlid : %s\n",line);
    else
        printf("invalid: %n",line);
}