//
// Created by rahul on 18/7/19.
//
#include <stdio.h>
#include <ctype.h>
int getword(int *word,int lim)
{
    int c,d,,comment(void),getch(void);
    void ungetch(int);
    char *w=word;
    while(isspace(c=getch()));
    if(c!=EOF)
        *w++=c;
    if(!isalpha(c) || c=='_' || c=='#') {
        for (; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            } else if (c == '\'' || c == '"') {
                for (; --lim > 0; w++)
                    if ((*w = getch()) == '\\')
                        *w++ = getch();
                    else if (*w == c) {
                        w++;
                        break;
                    } else if (*w == EOF)
                        break;
            }
    }
                else if(c=='\')
                if((d=getch())=='*')
                    c=comment();
                else
                    ungetch(d);
                *w='\0';
                return c;
}
int comment(void)
{
    int c;
    while((c=getch())!=EOF)
        if(c=='*')
            if((c=getch())=='/')
                break;
            else
                ungetch(c);

}