#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 100

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};
#define MAXBUF 1000
char  buf[MAXBUF];
int bufp=0;
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(char c)
{
  if(bufp >= MAXBUF)
  printf("BUFFER FULL\n");
  else
  buf[bufp++] =
}
void error(int , char *);
void getdef(void);
int getword(char * , int );
struct nlist *install(char * , char *);
struct nlist *lookup(char *);
void skipblanks(void);
void undef(char *);
void ungets(char *);
int main()
{
  char w[MAXWORD];
  struct nlist *p;
  while(getword(w , MAXWORD) != EOF)
  {
    if(strcmp(w , "#")==0)
    getdef();
    else if(!isalpha(w[0]))
    printf("%s" , w);
    else if((p=lookup(w))==NULL)
    printf("%s" , w);
    else
    ungets(p->defn); // ungets push all character untill a non character found
  }
  return 0;
}

void getdef(void)
{
int c, i;
char def[MAXWORD] , dir[MAXWORD] , name[MAXWORD];
skipblanks();
if(!isalpha(getword(dir , MAXWORD)))
error(dir[0] , "getdef : expecting a directive after #");
else if(strcmp(dir , "define")==0)
{
skipblanks();
if(!isalpha(getword(name, MAXWORD)))
error(name[0] , "getdef : non-alpha-name expected");
else
{
  skipblanks();
  for(i=0; i< MAXWORD-1 ; i++)
    if((def[i]=getch())==EOF || def[i]=='\n')
    break;
  def[i]='\0';
  if(i <= 0)
  error('\n' , "getdef: incomplete defination");
  else
  install(name , def);
}
}
else if(strcmp(dir , "undef") == 0)
{
  skipblanks();
  if(!isalpha(getword(name, MAXWORD)))
    error(name[0] , "undef : non-alpha -name expected");
  else{
    skipblanks();
    if(!isalpha(getword(name , MAXWORD)))
      error(name[0] , "getdef : non alpha in undef");
    else
      undef(name);
  }
}
else
error(dir[0] , "getdef: expecting a directive after #");
}

void error(int c , char *s)
{
  printf("error : %s\n" , s);
  while(c!=EOF && c!='\n')
  c=getch();
}

void skipblanks()
{
  int c;
  while((c=getch())==' ' || c=='\t')
  ;
  ungetch(c);
}
void undef(char *s)
{
  int h;
  unsigned h = hashtab[hash(s)];
  struct nlist *prev , *np;
  for(np=hashtab[h] ; np!=NULL ; np->next)
  {
    if(strcmp(s , n->name)==0)
    break;
    prev = np;
  }
  if(np!=NULL)
  {
    if(prev==NULL)
    hashtab[h] = np->next;
    else
    prev->next = np->next;
    free((void *)np->name);
    free((void *)np->defn);
    free((void *)np);
  }
}
