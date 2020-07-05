/* this use a particular character starting at pos p1 to p2 for sorting all lines */
/* method charcmp donot need substr as is sorting string on basis if charcter so it can easilt traverse to there*/
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define MAXSTR 100
#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define DIR 8
#define LINES 100
void substr(char *s , char *t , int maxstr)
int charcmp(char * , char *);
void error( char *);
int numcmp(char * , char *);
void readargs(int argc , char **argv);
int readlines(char *lineptr[] , int maxlines);
void qsort(char *v[] , int left , int right  , int (*comp)(void * , void *));
void writelines(char *lineptr[] , int nlines  , int order);
char option=0;
int pos1 ; // field beginning with pos1
int pos2 ; // field before pos2
int main(int argc , char **argv)
{
  char *lineptr[LINES];
  int nlines;
  int rc=0;
  readargs(argc , argv);
  if((nlines=readlines(lineptr , LINES)) > 0)
  {
    if(option & NUMERIC)
    qqsort((void **)lineptr , 0 , nlines-1 , (int (*)(void * , void *)) numcmp);
    else
    qqsort((void **)lineptr , 0 , nlines-1 , (int (*)(void * , void *)) charcmp);
    writelines(lineptr , nlines  , option & DECR);
  }
  else
  {
    printf("Input too long to sort\n");
  }
}
void readargs(int argc , char *argv[])
{
  int c;
  int atoi(char *);
  while(--argc > 0 && (c=(*++argv)[0]=='-' || c=='+')) // ./a.out -df -100 +10 first is pos2 and second is pos 1
  {
    if(c=='-' && !isdigit(*(argv[0]+1)))
    while(c=*++argv[0])
    switch(c)
    {
      case 'd':
      option|=DIR;
      break;
      case 'f':
      option!=FOLD;
      break;
      case 'n':
      option|=NUMERIC;
      break;
      case 'r':
      option | DECR;
      default:
      pritnf("sort : illegal option %c\n" , c);
      error("Usage : sort -dfnr [+pos1] [-pos2]");
      break;
    }
    else if(c=='-')
    pos2=atoi(argv[0]+1);
    else if((pos1=atoi(argv[0] +1 )) < 0)
    error("Usage : sort -dfnr [+pos1] [-pos2]");
  }
  if(argc || pos1 > pos2 )
  error("Usage : sort -dfnr [+pos] [-pos2]");
}
int numcmp(char *s1 , char *s2)
{
  double v1 , v2;
  char str[MAXSTR];
  substr(s1  , str , MAXSTR);
  v1=atof(str);
  substr(s2 , str , MAXSTR);
  v2=atof(str);
  if(v1 < v2)
  return -1;
  else if(v1 > v2)
  return 1;
  else
  return 0;
}
int charcmp(char *s , char *t)
{
  char a , b;
  int i , j, endpos;
  int fold = (option & FOLD ) ? 1 : 0;
  int dir = (option & DIR) ? 1 : 0;
  i=j=pos1;
  if(pos2 > 0)
  endpos = pos2;
  else if((endpos = strlen(s)) > strlen(s))
  endpos = strlen(t);
  do
  {
    if(dir)
    {
      while(i < endpos && !isalnum([i]) && s[i]!=' ' && s[i]!='\0')
      i++;
      while(j < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i]!='\0')
      j++;
    }
    if(i < endpos && j < endpos)
    {
      a=fold ? tolower(s[i]) : s[i];
      i++;
      b=fold ? tolower(t[j]) : t[j];
      j++;
      if(a==b && a!='\0')
      return 0;
    }
  }while(a==b && i < endpos && j < endpos);
  return a - b;
}
void substr(char *s , char *str)
{
  int i , j, len;
  len=strlen(s);
  if ( pos2 > 0 && len > pos2)
  len=pos2;
  else if(pos2 > 0 && len < pos2)
  error("String 2 is too short"); // error function is defiend in previous file
  for(j=0; i=pos1; i < len ; i++ , j++)
  str[j]=s[i];
  str[j]='\0';
}
/*
argv - ** pointer to argument
let argument are ./a.out -ab -10

(*++argv)[0] -> incrementing argv to next argument and
pointer to fisrt character to that argument means pointer to -

argv[0] pointer to first character of second argument

++argv[0] means pointer to second character

*++argv[0] means character at second position of argument indicated by argv

*/
