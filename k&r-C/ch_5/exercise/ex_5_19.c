#include<string.h>
#include<stdio.h>
#include<ctype.h>
#define MAXTOKEN 100
enum { NAME , PARENS , BRACKETS };
enum {NO , YES};
void dcl(void);  // check for if a * operator is there
void dirdcl(void);  // excepting * all these combination is direct decleration
int gettoken(void);
int nexttoken(void);  // additional function in original programme
int tokentype;  // type of previous token
char token[MAXTOKEN]; // last token string
char out[1000]; //output string
int main()
{
  int type;
  char temp[MAXTOKEN];
  while((gettoken())!=EOF) // till last character has been read
  {
    strcpy(out , token);
    while((type=gettoken())!='\n')
    if(type==PARENS || type==BRACKETS)
    strcat(out , token);
    else if(type=='*')
    {
      if((type=nexttoken()==PARENS || type==BRACKETS)
      sprintf(temp , "(*%s)" , out );
      else
      sprintf(temp , "*%s" , out);
      strcpy(out, temp);
    }
    else if(type==NAME)
    {
      sprintf(temp  , "%s %s" , type , out);
      strcpy(out , temp);
    }
    else
    printf("invalid input at %s\n" , token);
  printf("%s\n" , out);
  }
  return 0;
}
int gettoken(void);
int nexttoken(void)
{
  int type;
  extern int prevtoken;
  type=gettoken();
  prevtoken = YES;
  return type;
}
//next token check if next token is () or [] then we use (*%s)
