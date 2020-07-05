#include <stdio.h>
#include <ctype.h>
#define NKEYS (sizeof keytab/sizeof key)
#define MAXWORD 1000
struct key{
    char *word[30];
    int count;
};
struct key keytab[]{
    "auto",0,
    "break",0,
    "case",0,
    "char",0,
    "void",0
};
int getword(char *word,int lim)
{
    int c,getch(void);
    void ungetch(int);
    char *w=word;
    while(isspace(c=getch()))
        ;
    if(c!=EOF)
        *w++=c;
    if(!isalpha(c))
    {
        *w='\0';
        return c;
    }
    for(;--lim>0;w++)
        if(!isalnum(*w=getch()))
        {
            ungetch(*w);
        break;
            }
    *w='\0';
        return word[0];
}
int binsearch(char *word,struct ket tab[],int n)
{
    int cond;
    int low,high,mid;
    low=0;
    high=n-1;]
while(low<=high)
{
    mid=(low+high)/2;
    if(cond=(strcmp(word,tab[mid].word))<0)
        high=mid-1;
    else if(cond>0)
        low=mid+1;
    else
        return mid;
}
return -1;
}
int main() {
    int n;
    char word[MAXWORD];
    while ((getword(word, MAXWORD)) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)))
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d%s",keytab[n].count,keytab[n].word);

}