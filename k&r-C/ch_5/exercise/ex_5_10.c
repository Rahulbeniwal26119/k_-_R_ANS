#include<stdio.h>
#include<math.h>

//  note check calculator programme of chapter 4 to run it currectly
/****************
Big Note

use "*" instead of * in expr 11 2 + 5 "*"

****************/
void ungets(char *p)  // reciving
{
  while(*p)
  ungetch(*p++);

}
int main(int argc , char **argv)
{
  char s[MAXOP];
  double op2;
  int argcc=argc;
  while(--argc > 0)
  {
    ungets(" ");   // use to seprate the arguments
    ungets(*++argv); // passing pointer to argument and skipping the name of invoker
    switch(getop(s))
    {
      case NUMBER:
      push(atof(s));
      break;
      case '+':
      push(pop() + pop());
      break;
      case '*':
      push(pop() * pop());
      break;
      case '-':
      op2=pop();
      push(pop() - op2);
      break;
      case '/':
      op2=pop();
      if(op2!=0.0)
      push(pop() / op2);
      else
      printf("error : zero division error\n");
      break;
      default:
      printf("unknown command %s\n" , s);
      argc=1;
      break;
    }
  }
  printf("\t%.8g\n" , pop() );
}
