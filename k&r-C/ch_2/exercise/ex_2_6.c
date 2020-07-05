#include<stdio.h>
unsigned char  setbits(unsigned char  x , int p , int n , unsigned char  y)
{
    return x & ~(~(~0 << n) << (p-n)) | (y & ~(~0 << n )) << (p-n);
}
int main()
{
    unsigned char  a;
    a=100;
    printf("%u" , setbits( 100 , 3, 2 , 95));
}
 // 01100100
 // 01011111 95
 // 01100110 
 // 01011111 & 00000011 << (1) == 00000110 side one 
 // ~(00000011) << 1) == ~(00000110) = 11111001
 //01100100 & 11111001 | 00000110
 //01100000 | 00000110
 // 01100110