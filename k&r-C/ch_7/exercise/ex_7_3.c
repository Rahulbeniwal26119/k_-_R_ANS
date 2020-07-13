#include<stdio.h>
#include<stdargs.h>
#include<ctype.h>
#define LOCALFMT 100
void minprintf(char *fmt , ...)
{
  va_list ap;
  char *p , *sval;
  char localfmt[LOCALFMT];
  int i , ival;
  va_start(ap , fmt);
  unsigned uval;
  double dval;
  for(p=fmt ; *p ; p++)
  {
    if(*p!='%')
    {
      putchar(*p);
      continue;
    }
    i=0;
    localfmt[i++]='%';
    while(*(p+1) && !isalpha(*(p+1)))  // now store %10s like dcl
      localfmt[i++]=*++p;
    localfmt[i++] = *(p+1); // store complete format
    localfmt[i] = '\0';
    switch(*++p)
    {
      case 'd':
      case 'i':
      ival = va_arg(ap , int );
      printf(localfmt , ival);
      break;
      case 'x':
      case 'X':
      case 'u':
      case 'o':
      uval = va_arg(ap , unsigned );
      printf(localfmt , uval);
      break;
      case 'f':
      dval = va_args(ap , double);
      printf(localfmt , dval);
      break;
      case 's':
      sval = va_args(ap , char *);
      printf(localfmt , sval);
      break;
      default:
      printf(localfmt);
      break;
    }
  }
  va_end(ap);
}
