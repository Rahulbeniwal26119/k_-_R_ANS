#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ALLOCSIZE 10000 //size of avialiable space
static char allocbuf[ALLOCSIZE]; //buffer for allocbuf
static char *allocp=allocbuf; //net free position in buffer
char *alloc(int n) //return pointer to n character
{
  if(allocbuf+ALLOCSIZE-allocp>=n)  //space is enough
  {
    allocp=allocp+n;
    return allocp-n;  //old positiion
  }else
  return 0; // not enough room
}
void afree(char *p)
{
  if(p>=allocbuf && p<allocbuf+ALLOCSIZE)
  allocp=p;
}
#define MAXLEN 10000
int getlline(char *line,int max)
{
  int c;
  char  *t=line;
  while(--max>0 && (c=getchar())!=EOF && c!='\n')
  *line++=c;
  if(c=='\n')
  *line++=c;
  *line='\0';
  return line-t;
}
int strcmpp(char *s,char *t)
{
  while(*s==*t)
  {
    if(*s=='\0')
    return 0;
    s++,t++;

  }
  return *s-*t;
}
int readline(char *lineptr[],int maxlines)
{
int len,nlines;
char *p,line[MAXLEN];
nlines=0;
while((len=getlline(line,MAXLEN))>0)
if(nlines>=maxlines || (p=alloc(len))==NULL)
return -1;
else
{
  line[len-1]='\0';
  strcpy(p,line);
  lineptr[nlines++]=p;
}
}
void writelines(char *lineptr[],int nlines)
{
  int i=0;
  for(i=0;i<nlines;i++)
  printf("%s",lineptr[i]);//we can write it as *linrptr++;here *lineptr points to first line
}
void qcsort(char *v[],int left,int right)
{
  int i,last;
  void swap(char *v[],int i,int j);
  if(left>=right)
  return ;
  swap(v,left,(left+right)/2);
  for(i=left+1;i<=right;i++)
  if(strcmpp(v[i],v[left])<0)
  swap(v,++last,i);
  swap(v,left,last);
  qcsort(v,left,last-1);
  qcsort(v,last-1,right);
}
void swap(char *v[],int i,int j)
{
  char *temp;
  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}
