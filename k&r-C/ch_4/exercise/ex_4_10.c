// getch() -> Function use for getting a character either from stream or from buf array
// ungetch() -> Function use for pushing a extra character like 1 2+ can be interpreted as 1 2 + or 1 2exp as 1 2 exp
// These two can method  can be minimised into one getline method
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 100 //
#define MAXVAL 100
#define MAXOP 100
#define NUMBER '0' // signal that number was found
#define NAME 'n'   // signal that name was found
int sp = 0;
char buf[BUFSIZE];
int bufp = 0;
int getch();
void clear(); // setting stack pointer to beginning
void ungetch(int);
double val[MAXVAL];
int getop(char[]);
void push(double);
double pop(void);
int getlline(char [] , int );
void mathfunc(char[]);
int main()
{
    int type;
    double op2, op1;
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
        case 'c': // c for clear stack
            clear();
            break;
        case 'd': // d for copy a value on stack
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's': // for swap of both element
            op1 = pop();
            op2 = pop();
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
    sp = 0;
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
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("error : %s not support\n", s);
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
#define MAXLINE 100
int li = 0; // input line index
char line[MAXLINE];
int getop(char s[])
{
    int c, i;
    if (line[li] == '\0')
        if (getlline(line, MAXLINE) == 0)
            return 0;
        else
            li = 0;
    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (islower(c)) // for checking if a mathematical function appears or not
    {
        while (islower(s[++i] = c = line[li++]))
            ;
        s[i] = '\0';
        if (c != EOF)
                li--;
        if (strlen(s) > 1) // generally mathematical functions have abbrivated more than one character
            return NAME;
        else
            return c;
    }

    if (!isdigit(c) && c != '.' && c != '-') //checking if a float value with a negative sign appears
        return c;
    if (c == '-') // function atof also handle -num for convert it to negative numbers
        if (isdigit(c = line[li++]) || c == '.')
        {
            s[++i] = c;
        }
        else
        {li--;
            return '-';
        }
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    if (c != EOF)
    li--;
    return NUMBER;
}
// replacement of getch() and ungetch()
int getlline(char line[], int limit)
{
    int c;
    int len=0;
    while ((c = getchar()) != EOF && c != '\n')
        line[len++] = c;
    if (c == '\n')
        line[len++] = '\n';
    line[len] = '\0';
    return len;
}