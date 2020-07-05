//
// Created by Rahul on 6/19/2019.
//
#include <stdio.h>
float celsius(float fahr);
main()
{
    float fahr;
    for(fahr=0;fahr<=300;fahr+=20)
        printf("%f \t %f \n",fahr,celsius(fahr));
}
float celsius(float fahr)
{
    return (5.0/9.0)*(fahr-32);
}
