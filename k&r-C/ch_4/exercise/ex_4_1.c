#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
int getlin(char line[] , int max);
int strindex_version_1(char source[] , char destination[]);
int strindex_version_2(char s[] , char t[]);
char pattern[]="ould";
int main()
{
    char line[MAXLINE];
    int found=0;
    int pos;
    while(getlin(line , MAXLINE) > 0)
    if((pos=strindex_version_2(line , pattern)) >=0 )
    {
        printf("%d\t" ,pos);
        printf("%s" , line);
        ++found;
    }
}
int getlin(char s[] , int lim)
{
    int c , i=0;
    while(--lim > 0 && (c=getchar())!=EOF && c!='\n')
    s[i++]=c;
    if(c=='\n')
    s[i++]=c;
    s[i]='\0';
    return i; 
}
int strindex_version_1(char source[] , char target[])
{
    int i , j ,k;
    int found=0;
    int pos;
    for(i=0;source[i];i++)
    {
    for(j=i , k=0; target[k]!='\0'  && source[j]==target[k]; j++ , k++);
    if (k > 0 && target[k]=='\0' && source[i]!='\0')
    {
        found++;
        pos=i;
    }
    }
    if(found)
    return pos;
    else
    return -1;
}
int strindex_version_2(char s[] , char t[])
{
int i , j ,k;
for(i=strlen(s) - strlen(t)  -1 ;i>=0;--i)
{
    for(j=i , k=0; t[k]!='\0' && s[j]==t[k];j++ ,k++);
    if( k>0 && t[k]=='\0')
    return i;
}
return -1;
}

// second version start scanning from last  excluding the number of characters = length of target  and starting decresing the search area from n to n+1 and further 
