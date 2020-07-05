#include<stdio.h>
#include<ctype.h>
int bufp=0;
#define MAXLEN 1000
int buf[MAXLEN];
int getch()
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
  if(bufp >= MAXLEN)
  printf("ungetch() : size exceed\n");
  else
  buf[bufp++]=c;
}
int getfloat(float *pn)
{
  int  c , sign=1;
  float power = 1.0;
  while(isspace(c=getch()));
  if(!isdigit(c) && c!=EOF && c!='+' && c!='-' && c!='.')
  {
    ungetch(c);
    return 0;
  }
  sign = (c=='-') ? -1 : 1;
  if(c=='+' || c=='-')
  c=getch();
  for(*pn=0.0 ; isdigit(c) ; c=getch())
  {
    *pn=*pn * 10.0 + c - '0';
  }
  if(c=='.')
  c=getch();
  for(power=1.0 ; isdigit(c) ; c=getch())
  {*pn=*pn*10.0  + c - '0';
  power*=10.0;
}
*pn = (*pn * sign) / power ;
if(c!=EOF)
ungetch(c);
return c;
}
int main()
{
  float arr[MAXLEN];
  int n;
  for(n=0; n < MAXLEN && getfloat(&arr[n]) != EOF ; n++);
  for(int i=0; i < n ; i++)
  printf("%f \t" , arr[n]);
}
