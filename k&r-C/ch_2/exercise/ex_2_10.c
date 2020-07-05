#include<stdio.h>
int lower(char c)
{
    return (c >='A' && c<='Z') ? c-'A'+'a' : c;
}
int main()
{
    char a[]="RahUl";
    int i=0;
    while(a[i])
    printf("%c" , lower(a[i++]));
}