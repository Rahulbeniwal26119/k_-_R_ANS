#include <stdio.h>
void rcomment(int c); /* method for removing long line comment , remember c doesnot support nesting of comment */
void in_comment(void);  
void echo_quote(int);
void in_comment_2(void);  //method for removing // comments

int main()
{
    int c , d;
    while((c=getchar())!=EOF)
    {
        rcomment(c);
    }
    return 0;
}

void rcomment(c)
{
    int d;
    if(c=='/')
        if((d=getchar())=='*')
            in_comment();
        else if(d=='/')
        {
            // putchar(c);
            in_comment_2();
        }
        else 
        {
            putchar(c);
            putchar(d);
        }
    else if(c=='\'' || c=='"')
        echo_quote(c);
    else 
        putchar(c);
}

void in_comment(void)
{
    int c , d;
    c=getchar();
    d=getchar();
    while(c!='*' && d!='/')
    {
        c=d;
        d=getchar();
    }
}

void echo_quote(int c)
{
    int d;
    putchar(c);
    while((d=getchar())!=c)
        {
            putchar(d);
            if(d=='\\')
                putchar(getchar());
        }
        putchar(d);
}
void in_comment_2()
{
    int c ;
    while((c=getchar())!='\n');
}