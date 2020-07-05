// calculator programme for handling - and % operator
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define BUFSIZE 100
#define MAXVAL 100
#define MAXOP 100
#define NUMBER '0'
int sp=0;
char buf[BUFSIZE];
int bufp=0;
int getch();
void ungetch(int);
double val[MAXVAL];
int getop(char []);
void push(double);
double pop(void);
int main()
{
    int type;
    double op2;
    int op2_mod;
    char s[MAXOP];
    while((type=getop(s))!=EOF)
    {
        switch(type)
        {
            case NUMBER:
            push(atof(s));
            break;
            case '+':
            push(pop()+pop());
            break;
            case '*':
            push(pop() * pop());
            break;
            case '-':
            op2=pop();
            push(pop() - op2);
            break;
            case '/':
            op2=pop();
            if(op2!=0.0)
            push(pop() / op2);
            break;
            case '%':
            op2=pop();
            if(op2!=0.0)
            push(fmod(pop() , op2));  // fmod calculate the reminder on the top 
            else
            printf("error : zero divisor");
            case '\n':
            printf("\t%.8g\n",pop());
            break;
            default:
            printf("error: unknown command %s\n" , s);
            break;
        }
    }
    return 0;
}
void push(double f)
{
    if(sp < MAXVAL)
    val[sp++]=f;
    else 
    printf("error: stack full , cannot push %g\n " , f);
}
double pop(void)
{
    if(sp > 0)
    return val[--sp];
    else 
    {
        printf("error: stack empty\n");
    return 0.0;
    }
}  
int getop(char s[])
{
int c ,i;
while((s[0]=c=getch())==' ' || c=='\t');
s[1]='\0';
 i=0;
if(!isdigit(c) && c!='.' && c!='-')
return c;
if(c=='-')  // function atof also handle -num for convert it to negative numbers 
if(isdigit(c=getch()) || c=='.')
{
s[++i]=c;
}else 
{
    if(c!=EOF)
    ungetch(c);
    return '-';
}
if(isdigit(c))
while(isdigit(s[++i]=c=getch()));
if(c=='.')
while(isdigit(s[++i] = c= getch()));
s[i]='\0';
if(c!=EOF)
ungetch(c);
return NUMBER;
}
int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if(bufp >= BUFSIZE)
    printf("ungetch : too many characters\n");
    else 
    buf[bufp++]=c;
}