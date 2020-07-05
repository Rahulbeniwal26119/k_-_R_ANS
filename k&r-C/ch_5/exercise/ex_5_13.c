#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFLINES 10 // default lines to print
#define LINES 100 // max lines to print
#define MAXLEN 100 // max length of input lines
void error(char *);
int getlline(char *s, int lim)
{
  int c;
  char *t = s;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;
  *s = '\0';
  return s - t;
}
int main(int argc, char **argv)
{
  char *p;
  char *buf;            //pointer to large buf
  char *bufend;         //end of the buffer
  char line[MAXLEN];    //current input lines
  char *lineptr[LINES]; //pointer to lines read
  int first, i, last, len, n, nlines;
  if (argc == 1)
    n = DEFLINES;
  else if (argc == 2 && (*++argv)[0] == '-')
    n = atoi(argv[0] + 1);
  else
    error("Usage : tail [ -n ]");
  if (n < 1 || n > LINES) // unreasonable value for n
    n = LINES;
  for (i = 0; i < LINES; i++)
    lineptr[i] = NULL;
  if ((p = buf = (char *)malloc(LINES * MAXLEN)) == NULL) // providing storage pointers for fixed length string
    error("tail : Cannot allocate buf");
  bufend = buf + LINES * MAXLEN; // finding the buffer end
  last = 0;                      // index of last line read
  nlines = 0;                    // number of lines has been read
  while ((len = getlline(line, MAXLEN)) > 0)
  {
    if (p + len + 1 >= bufend)
      p = buf;
    lineptr[last] = p;
    strcpy(lineptr[last], line);
    if(++last > LINES)
    last=0;
    p += len + 1;
    nlines++;
  }
  if (n  > nlines)
    n = nlines; // if tail lines are greater than the line in programme then it set to total lines of programme
  first = last - n;
  // if (first < 0)
  //   first += LINES;  // this part is optional
  for (i = first; n-- > 0; i=(i+1)%LINES)
    printf("%s\n", lineptr[i]);
  return 0;
}
void error(char *s)
{
  printf("%s\n", s);
  exit(1);
}
