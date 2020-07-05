/*dcl pass a declerator*/
#include<stdio.h>
#include<string,h>
#include<ctype.h>
void dcl(void/* arguments */) {
  int ns;
  for(ns=0;gettoken()='*';)//count *'s'
  ns++;
  dirdcl();
  while(ns-->0)
  strcat(out,"pointer to ");
  /* code */
}
void dirdcl(void)
{
  int type;
  if(gettoken=='(') //dcl
  {
    dcl();
    if(tokentype!=')')
    printf(" \n missing \n");
  }else if(tokentype==NAME) //variable name
  strcpy(name,token);
  else
  printf("error seareching for name of dcl\n");
while((type=gettoken())=PAREN || type==BRACKETS)
if(type==BRACKETS)
strcat(out,"fucntion returning ");
else
{
  strcat(out,"array");
  strcat(out,"token");
  strcat(out,"of");
}
}
