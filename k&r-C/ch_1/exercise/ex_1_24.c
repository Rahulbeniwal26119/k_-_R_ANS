#include <stdio.h>
int brace, paren, brack;
void in_quote(int c);
void in_comment(void);
void search(int c);

int main()
{
    int c;
    extern int brack, paren, brace;
    while ((c = getchar()) != EOF)
    {
        if (c == '/')
        {
            if ((c = getchar()) == '*')
                in_comment();
            else
                search(c);
        }
        else if (c == '\'' || c == '"')
            in_quote(c);
        else
        search(c);
    }
    if(brace < 0)
        {
            printf("Unbalanced braces\n");
            brace=0;
        }
    else  if(brack < 0)
    {
        printf("Unbalance brackets\n");
        brack=0;
    }
    else if(paren < 0)
    {
        printf("Unbalance parenthesis\n");
    }
    if(brace > 0)
        printf("Unbalanced braces\n");
    else if(brack > 0)
        printf("Unbalanced brackets\n");    
    else if(paren > 0)
        printf("Unbalanced parenthesis\n");
}
void search(int c)
{
    extern int brace , brack , paren;
    if(c=='{')
        ++brace;
    else if(c=='[')
        ++brack;
    else if(c=='(')
        ++paren;
    else if(c==']')
        --brack;
    else if(c=='}')
        --brace;
    else if(c==')')
        --paren;
}

void in_comment(void)
{
    int c , d;
    c=getchar();
    d=getchar();
    while(c!='*' || d!='/')
    {
        c=d;
        c=getchar();
    }
}
void in_quote(int c)
{
    int d;
    while((d=getchar())!=c)
    {
        if(d=='\\')
            getchar();
    }
}