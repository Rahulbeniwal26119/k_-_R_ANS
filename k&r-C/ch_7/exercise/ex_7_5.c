#include<stdio.h>
#include<ctype.h>
#define NUMBER '0'
int getop(char s[]) // get oprerand and operator 
{
    int c , i , rc;
    static char lastc[]= " "; // array of only 2 char for remebering only one last character 
    // lastc is static for remembering the valus from last function calls 
    sscanf(lastc , "%c" , &c); // ungetch() for a single character or for remember the the lastcharacter 
    // getting last character value from sscanf() eg 12+ lastc has + for next term 
   // c=last[0] is also quivalent to above one 
    lastc[0] = ' ';
    while((s[0]=c)==' '  || c=='\t')
    {
        if(scanf("%c" , c)==EOF)
            c=EOF;
    }
    s[1]='\0';
    if(!isdigit(c) && c!='.')
    {
        return c;
    }
    i=0;
    if(isdigit(c))
    do{
        rc=scanf("%c" , &c);
        if(!isdigit(s[++i]=c))
            break;
    }while(rc!=EOF);
    if(c=='.')
    do{
        rc=scanf("%c" , &c);
        if(!isdigit(s[++i]=c))
            break;
    }while(rc!=EOF); // scanf read EOF as -1 scanf resumes searching for next character after the last character already convereted 
    s[i] = '\0';
    if(rc!=EOF)
        lastc[0] = c;
    return NUMBER;
}