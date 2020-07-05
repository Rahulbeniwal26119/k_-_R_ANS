#include<stdio.h>
int  str_pbrk(char s1[] , char s2[])
{
    int i , j, k;
    for(i=k=0;s1[i];i++)
    {
    for(j=0;s2[j] && s2[j]!=s1[i];j++);
    if(s2[j]!='\0')
    return i;
    }
    return -1;
}
int main()
{
     char s1[]="rhu";
     char s2[]="beniwal";
    printf("%d" ,str_pbrk(s1 , s2));
}