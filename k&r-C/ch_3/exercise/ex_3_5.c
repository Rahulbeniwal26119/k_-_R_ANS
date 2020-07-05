#include<stdio.h>
void reverse(char s[])
{
    int len=0;
    int i=0;
    char temp;
    while(s[++len]);
    int mid=len/2;
    for(int i=0; i<mid ; i++)
    {
        temp = s[i];
        s[i]=s[len-1];
        s[len-1]=temp;
        --len;
    }
}
void itob(int n, char s[] , int b)
{
    int i , j , sign;
    void reverse(char s[]);
    if((sign=n) < 0)
    n=-n;
    i=0;
    do
    {
        j=n%b;
        s[i++] = ( j <= 9 ) ? j + '0' : j+'a'-10;
    } while ((n/=b)>0);
    s[i++]='-';
    s[i]='\0';
    reverse(s);
}
int main()
{
    int a=-11;
    char  arr[20];
    itob(a , arr , 2);
    printf("%s" , arr);
}