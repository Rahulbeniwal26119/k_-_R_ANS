#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
struct tnode{
  char *word;
  int match;
  struct tnode *left;
  struct tnode *right;
};
char buf[MAXSIZE];
int bufp=0;
char word[MAXSIZE];
int getch()
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(char c)
{
  (bufp >= MAXSIZE-1) ? printf("Stack Overflow") : (buf[bufp++]=c);
}
struct tnode *talloc(void)
{
  return (struct tnode *)malloc(sizeof(struct tnode));
}
char *strdupp(char *s)
{
  char *p;
  p=(char *)malloc(strlen(s) + 1);
  if(p!=NULL)
  {
    strcpy(p , s);
  }
  return p;
}
void treexprint(struct tnode *p);
int getword(char *word , int lim )
{
  int c;
  char *w = word;
  while(isspace(c=getch()))
  ;
  if(c!=EOF)
  *w++ = c;
  if(!isalpha(c))
  {
    *w='\0';
    return c;
  }
  for(; --lim > 0 ; w++)
  {
    if(!isalnum(*w=getch()))
    {
      ungetch(*w);
      break;
    }
  }
  *w='\0';
  return word[0];
}

#define MAXWORD 100
#define YES 1
#define NO 0
struct tnode *addxtree(struct tnode * , char * , int , int *);
int getword(char *w , int );
int main(int argc  , char **argv)
{
  struct tnode *root;
  int found=NO;
  int num;   // number of first identical character
  num=(--argc && (*++argv)[0]=='-') ? atoi(argv[0]+1) : 6;
  root=NULL;
  while(getword(word , MAXWORD)!=EOF)
  {
    if(isalpha(word[0]) && strlen(word) >= num)
    {
    root=addxtree(root , word ,num , &found);
    printf("%s" , root->word);
  }
    found=NO;
  }
  treexprint(root);
  return 0;
}
struct tnode *addxtree(struct tnode *p , char *w , int num , int *found)
{
  int cond;
  if(p==NULL)
  {
    p=talloc();
    p->word = strdup(w);
    p-> match = *found;
    p->left = p->right = NULL;
  }
  else if((cond=compare(w , p , num , found)) < 0) //comparing p with the upcoming word if upcoming word is mathcing then *found is set to YES and
  // method set p->match=YES if it is a match
  p->left = addxtree(p->left , w , num , found);
  else if(cond > 0)
  p->right = addxtree(p->right , w , num , found);
  return p;
}
int compare(char *s , struct tnode *p , int num ,  int *found)
{
  int i;
  char *t = p->word;
  for(i=0; *s==*t ; s++ , t++, i++) // donot use ; here otherwise all completly matched word will print
  if(*s=='\0')
  return 0;
  if(i >= num )
  {
    *found=YES;
    p->match = YES;
  }
  return *s - *t;
}
void treexprint(struct tnode *p)
{
  if(p!=NULL)
  {
  treexprint(p->left);
  if(p->match)
  printf("%s\n" , p->word);
  treexprint(p->right);
}
}
