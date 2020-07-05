#include<stdio.h>
unsigned char invert(unsigned char x , int p , int n )
{
    return x ^ (~(~0 << n) << (p-n));
}
int main()
{
unsigned char x=200;
printf("%u" , invert(x , 2 , 2));
}
// 11001000
// 11001011
// 11001000 ^ (00000011) 
// 11001011
