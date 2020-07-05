#include<stdio.h>
#include<math.h>
int  power(int num , int pow)
{
    int base=1;
        if(pow==0)
    return 1;
    else 
    while(pow!=0)
    {
        base=base*16;
        pow--;
    }
    return base;
}
void strreverse(char s[] , int len)
{
    int mid;
    char temp;
    mid=len/2;
    for(int i=0;i<=mid/2;i++)
    {
    temp=s[i];
    s[i]=s[len-1];
    s[len-1]=temp;
    --len;
    }

}
int strlength(char s[])
{
    int i=0;
    while(s[i] && ++i);
    return i;
}
int htoi(char s[])
{
    int i;
    int number=0;
    int length=strlength(s);
    strreverse(s , length);
    if(s[length-1]=='0' && (s[length-2]=='x' || s[length-2]=='X'))
    length-=2;
    for(i=0;i<length;++i)
    {
        if(s[i] >='0' && s[i] <='9' )
        number+=(s[i]-'0')*(power(16,i));
        if(s[i] >='a' && s[i] >='f')
        number+=(s[i]-'a' + 10)*power(16,i);
        if(s[i]>='A' && s[i] <='F')
        number+=(s[i]-'A'+10)*power(16,i);
    }
    return number;
}
int main()
{
    char str[20];
    scanf("%s" , str);
     printf("%d" , htoi(str));
}
