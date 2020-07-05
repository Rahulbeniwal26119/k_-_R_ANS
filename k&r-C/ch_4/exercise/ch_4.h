#include<stdio.h>
#include<ctype.h>
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
double atof(char s[])
{
    double val , power;
    int i , sign;
    for(i=0;isspace(s[i]);i++);
    sign=(s[i]=='-') ? -1 :1;
    if(s[i]=='-' || s[i]=='+')
    i++;
    val=0;
    for(val=0.0;isdigit(s[i]);i++)
    val=val*10+s[i]-'0';
    if(s[i]=='.')
    i++;
    for(power=1.0;isdigit(s[i]);i++)
    {
        val=val*10+(s[i]-'0');
        power*=10.0;
    }
    return sign * val / power;

}
int atoi(char s[])
{
    double atof(char s[]);
    return (int)(atof(s));
}