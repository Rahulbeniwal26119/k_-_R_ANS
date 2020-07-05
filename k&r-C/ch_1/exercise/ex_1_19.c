#include<stdio.h>
#define MAXLEN 1000
void reverser(char a[] , int len)
{
int pivot=len/2;
int last=len-1;
char temp;
for(int i=0;i<pivot;i++)
{
temp=a[i];
a[i]=a[last];
a[last]=temp;
last--;
}
}
int  strllen(char line[] , int maxlen)
{
    int c;
    int i=0;
    while((c=getchar())!=EOF && c!='\n')
    {
        line[i]=c;
        ++i;
    }
    line[i]='\0';
    return i;
}
int main()
{
    int len;
    int arr[MAXLEN];
    while((len=strllen(arr , MAXLEN))>0)
    {
        reverser(arr , len);
        printf("%s\n" , arr);
    }
}