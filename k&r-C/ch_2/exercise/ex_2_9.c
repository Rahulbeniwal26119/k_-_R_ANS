#include<stdio.h>
int bitcount(unsigned x)
{
    int b;
    for(b=0;x!=0 ; x>>=1)
    if(x & 01)
    b++;
    return b;
}
int bitcount_version_2(unsigned x)
{
    int b;
    for(b=0;x!=0; x&=x-1)
    ++b;
    return b;
}
int main()
{
    printf("%d" , bitcount(1010));
}
/*
x=1010
x-1=1001
x & (x-1) = 1000
x=1000
x-1=0100
/*