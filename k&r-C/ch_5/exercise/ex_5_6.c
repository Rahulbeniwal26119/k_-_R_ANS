#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NUMBER '0' // signal if a number is found

int atoi(char *s)
{
  int n = 0, sign;
  while (isspace(*s) && s++)
    ;
  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-')
    s++;
  while (isdigit(*s))
  {
    n = n * 10 + *s - '0';
    s++;
  }
  return sign * n;
}

int getlline(char *s, int lim)
{
  int c;
  char *t = s;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;
  *s = '\0';
  return s - t;
}

void reverse(char *s)
{
  int c;
  char *t;
  for (t = s + (strlen(s) - 1); s < t; s++, t--)
  {
    c = *s;
    *s = *t;
    *t = c;
  }
}

void itoa(int n, char *s)
{
  int sign = (n < 0) ? -1 : 1;
  sign < 0 ? -n : n;
  static int i;
  if (n != 0)
  {
    itoa(n / 10, s);
    *(s + i) = n % 10 + '0';
    *(s + ++i) = '\0';
    return;
    int main()
    {
      int a = 1234;
      int sign;
      char s[10];
      atoi(a, s);
      printf("%s", s);
    }
  }
}

int strindex(char *s, char *t)
{
  char *b = s;
  char *p, *r;
  for (; *s; s++)
  {
    for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
      ;
    if (r > t && *r == '\0')
      return s - b;
  }
  return -1;
}

double atof(char *s)
{
  double val, power;
  int sign;
  for (; isspace(*s); s++)
    ;
  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-')
    s++;
  for (val = 0.0; isdigit(*s); s++)
    val = 10.0 * val + *s - '0';
  if (*s == '.')
    s++;
  for (power = 1.0; isdigit(*s); s++)
  {
    val = 10.0 * val + *s - '0';
    power *= 10.0;
  }
  return sign * val / power;
}

int getop(char *s)
{
  int c;
  while ((*s = c = getch()) == ' ' || c == '\t')
    ;
  *(s + 1) = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  if (isdigit(c))
    while (isdigit(*++s = c = getchar()))
      ;
  if (c == '.')
    while (isdigit(*++s = c = getch()))
      ;
  *s = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}
