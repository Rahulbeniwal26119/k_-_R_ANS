/* read only modified getch and ungetch function*/ 

// I am keeping all the changes made in basic calculator example in k&r 
// to all exercise involing some modification
#include <stdio.h>
#include <math.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 100  // 
#define MAXVAL 100
#define MAXOP 100
#define NUMBER '0'  // signal that number was found 
#define NAME 'n'  // signal that name was found 
int sp = 0;
char buf[BUFSIZE];
int bufp = 0;
int getch();
void clear();  // setting stack pointer to beginning
void ungetch(int);
double val[MAXVAL];
int getop(char[]);
void push(double);
double pop(void);
void mathfunc(char []);
int main()
{
    int type;
    double op2 , op1;
    int op2_mod;
    char s[MAXOP];
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2)); // fmod calculate the reminder on the top
            else
                printf("error : zero divisor");
            break;
        case NAME:
        mathfunc(s);
        break;
        case '?':
            op2 = pop();
            printf("\t %.8g\n", op2);
            push(op2);
            break;
        case 'c':  // c for clear stack 
            clear();
            break;
        case 'd':  // d for copy a value on stack 
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':  // for swap of both element 
            op1=pop();
            op2=pop();
            push(op1);
            push(op2);
        case '\n':  
        // newline charcter is used for showing the topmost value on stack 
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
void clear()
{
    sp=0;
}
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full , cannot push %g\n ", f);
}
void mathfunc(char s[])
{
    double op2;
    if(strcmp(s , "sin")==0)
    push(sin(pop()));
    else if(strcmp(s , "cos")==0)
    push(cos(pop()));
    else if(strcmp(s , "exp")==0)
    push(exp(pop()));
    else if(strcmp(s , "pow")==0)
    {
        op2=pop();
        push(pow(pop() , op2));
    }
    else 
    printf("error : %s not support\n" , s);
    
}
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
int getop(char s[])
{
    int c, i;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if(islower(c))  // for checking if a mathematical function appears or not 
    {
    while(islower(s[++i] = c = getch()))
    ;
    s[i]='\0';
    if(c!=EOF)
    ungetch(c);
    if(strlen(s) > 1) // generally mathematical functions have abbrivated more than one character 
    return NAME;
    else 
    return c;
    }
    
    if (!isdigit(c) && c != '.' && c != '-')  //checking if a float value with a negative sign appears 
        return c;
    if (c == '-') // function atof also handle -num for convert it to negative numbers
        if (isdigit(c = getch()) || c == '.')
        {
            s[++i] = c;
        }
        else
        {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

// if there is only one character so no need of a array a simple variable will do
char buf_single=0;
int getch()
{
    int c;
    if(buf_single!=0)
    c=buf_single;
    else 
    c=getchar();
    buf_single=0;
    return c;
}
void ungetch(int c)
{
    if(buf_single != 0)
    printf("ungetch : too many characters\n");
    else 
    buf_single=c;
}