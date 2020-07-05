#include<stdio.h>
void itoa(char s[] , int n)
{
    static int i;
    if( n / 10)
    itoa( s , n/10);
    else{
        i=0;
        if( n < 0)
        s[i++]='-';
    }
    s[i++]=abs(n)%10+'0';
    s[i]='\0';
}