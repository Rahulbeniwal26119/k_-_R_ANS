#include<stdio.h>
unsigned  rightrot( char x , int n)
{
    int wordlength(void);
    int rbit;
    while(n-->0)
    {
        rbit=(x&1) << (wordlength() - 1);
        x=x>>1;
        x=x | rbit;
    }
    return x;
}
int wordlength(void)
{
    int i;
    unsigned  v = (unsigned ) ~0;
    for(i=1; (v = v >> 1) >0 ; i++);
    return i; 
}
int main()
{
    printf("%u" , rightrot(100 , 1) );
}
/*
01100100
00001100  for 3
00110010 for 1
*/