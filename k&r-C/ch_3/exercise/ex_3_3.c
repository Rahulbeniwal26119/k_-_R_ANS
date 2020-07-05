#include<stdio.h>
void expand(char s1[] , char s2[])
{
 char c;
 int i ,j;
 i=j=0;
 while ((c=s1[i++]))  // for second iterations s[2]=='a' s[3]!='-' so else come in play  
     if(s1[i]=='-' && s1[i+1] >=c) // consider an example of a - z
{   // for  a-a
    // s[0]=0 while true , s[1]='-' true and s1[2] >= 'a' True
     i++;  
     while(c < s1[i]) // False 
     s2[j++]=c++;  
}
else
{
    s2[j++]=c;
}
s2[j]='\0';
}
int main()
{
    char s1[]="-a-z-";
    char s2[50];
    expand(s1 , s2);
    printf("%s" , s2);
}