#include<stdio.h>
void squeeze(char s1[] , char s2[])
{
    int match=0;
    int i , j;
    i=j=0;
    int k=0;
    for(;s1[i];i++)
    {
    for(j=0;s2[j];j++)
    {
        if(s1[i]==s2[j])
        {
        match=1;
        break;
        }
        else
        {
            match=0;
        }
        
    }
    if(match==0)
    s1[k++]=s1[i];
    }
s1[k]='\0';
}
/* use  any of these first is most simplest implementation and second one is compact one */
void squeesze_2(char s1[] , char s2[])
{
    int i  , j, k;
    for(i=k=0;s1[i];i++){
    for(j=0;s2[j] && s2[j]!=s1[i];j++);
    if(s2[j]=='\0')
    s1[k++]=s1[i];
    }
    s1[k]='\0'; 
}
int main()
{
    char  s1[]="rahul";
    char  s2[]="rahul";
    squeeze(s1 , s2);
    printf("%s\n" , s1);
}