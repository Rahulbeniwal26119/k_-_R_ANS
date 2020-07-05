#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 1000
int buf[BUFSIZE];
int bufp = 0;
int getch()
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("Buffer is completely filled no more space\n");
  else
    buf[bufp++] = c;
}
int getint(int *pn)
{

  int c, sign;
  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (!isdigit(c))
  {
    ungetch(c); //
    return 0;
  }

  for (*pn = 0; isdigit(c); c = getch())
  {
    *pn = *pn * 10 + c - '0';
    *pn *= sign;
  }
  // modification is here
  if (c != EOF)
    ungetch(c); // u can ignore it by using c=getchar()
  return c;
}
int main()
{
  int signal = 0;
  int n, array[BUFSIZE], getint(int *);
  for (n = 0; n < BUFSIZE && (signal = getint(&array[n])) != EOF && signal; n++)
    ;
  for (int i = 0; i < n; i++)
    printf("%d\t", array[i]);
}
