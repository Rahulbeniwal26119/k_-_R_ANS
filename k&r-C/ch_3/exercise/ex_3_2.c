#include<stdio.h>
void escape(char s[] , char t[])
{
    int i , j;
    for(i=j=0;t[i]!='\0';i++)
        switch(t[i])
        {
        case '\n':
        s[j++]='\\';
        s[j++]='n';
        break;
        case '\t':
        s[j++]='\\';
        s[j++]='t';
        break;
        default:
        s[j++]=t[i];
        break;
    }
    s[j]='\0';
}
void unescape(char s[] , char t[])
{
    int i  , j;
    for(i=j=0;t[i];i++)
    if(t[i]!='\\')
    s[j++]=t[i];
    else
    switch(t[++i])
    {
        case 'n':
        s[j++]='\n';
        break;
        case 't':
        s[j++]='\t';
        break;
        default:
        s[j++]='\\';
        s[j++]=t[i];
        break;
    }
    s[j]='\0';
}
int main()
{
    char s[]="rahul\t   beniwal\n";
    char p[100];
    unescape(p, s);
    printf("%s" , p);
}