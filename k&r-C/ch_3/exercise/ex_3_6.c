#include<stdio.h>
#define abs(x) ((x) < 0 ? (-x) : (x))
void reverse(char s[])
{
    int len=0;
    int i=0;
    while(s[++len]);
    int mid=len/2;
    // if someone is reading this code please tellme 
    // why this not working if use i < len/2 instead of using mid;
    // i found it , because len is changing continiously 
    for(;i<mid;i++)
    {
        char temp;
        temp=s[i];
        s[i]=s[len-1];
        s[len-1]=temp;
        --len;
    } 
}
void itoa(int n, char s[] , int w)
{
    int i , sign;
    void reverse(char s[]);
    sign=n;
    i=0;
    do{
        s[i++]=abs(n%10)+'0';
    }
    while((n/=10) > 0);
    if( sign < 0)
    s[i++]='-';
    while(i < w)
    s[i++]=' ';
    s[i]='\0';
    reverse(s);
}
int main()
{
    int a=1000;
    char s[10];
    itoa(a , s , 6);
    printf("%s" , s);
}
