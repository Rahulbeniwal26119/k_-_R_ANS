/*
 tip:-
Formatting a document may help u in debugging*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 5000
#define NUMERIC 1
#define DECR 2
#define LINES 100
#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSIZE_BUF 5000 //maximum storage for storing lines
char *lineptr[MAXLINES];
char buf[MAXSIZE_BUF];
char *lineptr[MAXLINES];
char buf[MAXSIZE_BUF];
char *bufp = buf; // next free postion
char *alloc(int n)
{
  char *p;
  if (buf + MAXSIZE_BUF - bufp >= n)
  {
    bufp += n;
    return bufp - n;
  }
  else
    return 0;
}
void afree(char *p)
{
  if (p >= buf && p <= buf + MAXSIZE_BUF)
    bufp = p;
}
int getlline(char a[], int len)
{
  int c;
  int i = 0;
  while ((c = getchar()) != EOF && c != '\n')
    a[i++] = c;
  if (c == '\n')
    a[i++] = '\n';
  a[i] = '\0';
  return i;
}
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines = 0;
  char line[MAXLEN];
  char *p;
  while ((len = getlline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else
    {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}
/*  writelines is modified for handling decrement ordering */
void writelines(char *lineptr[], int nlines, int decr)
{
  int i;
  if (decr)
  {
    for (i = nlines - 1; i >= 0; i--)
      printf("%s", lineptr[i]);
  }
  else
  {
    for (i = 0; i < nlines; i++)
      printf("%s\n", lineptr[i]);
  }
}
char *lineptr[MAXLINES];
void qqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
// int numcmp(char * , char *)
void swap(void *v[], int i, int j)
{
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
int numcmp(char *s1, char *s2)
{
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  if (v1 > v2)
    return 1;
  else
    return 0;
}

static char option = 0;

// int main(int argc, char **argv)
// {
//   int nlines;
//   int c, rc = 0;
//   int numeric = 0;
//   while (--argc > 0 && (*++argv)[0] == '-')
//     while (c = *++argv[0])
//       switch (c)
//       {
//       case 'n':
//         option |= NUMERIC;
//         break;
//       case 'r':
//         option |= DECR;
//         break;
//       default:
//         printf("Sort: illegal option %c\n", c);
//         argc = 1;
//         rc = -1;
//         break;
//       }
//   if (argc)
//     printf("Usage : sort -nr \n");
//   else if ((nlines = readlines(lineptr, LINES)) > 0)
//   {
//     if (option & NUMERIC)
//       qqsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp);
//     else
//       qqsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))strcmp);
//     writelines(lineptr, nlines, option & DECR);
//   }
//   else
//   {
//     printf("Input too long too sort");
//     rc = -1;
//   }
//   return rc;
// }
void qqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);
  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
       swap(v, ++last, i);
  swap(v, last, left);
  qqsort(v, left, last - 1, comp);
  qqsort(v, last + 1, right, comp);
}
/* explaination
option = 0
option | NUMERIC = 00000000 | 00000001 = 00000001
option | DECR   = 00000001  | 00000010 = 00000011
option & NUMERIC  = 00000011 & 00000001 = 00000001 -> TRUE
option & DECR = 00000011 & 00000010 = 00000010 -> True

so | and & are efficient ways to join one or more options or flag in a single variable */
