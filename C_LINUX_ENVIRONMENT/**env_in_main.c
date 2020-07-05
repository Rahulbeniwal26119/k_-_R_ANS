#include<stdio.h>
int main(int argc, char **argv , char **env) // main function syntax
{
int i=0;
printf("\n cmdline args count=%d",argc); //argc count the number of argument given in shell including executable file to
/* first argument in executable name only*/
printf("\n name =%s",*argv);  //*argv is shows first argument argv[0];
for(i=1;i<argc;i++)
printf("\n arg %d = %s",i,argv[i]);
i=0;
while(*env!=NULL) //*env is a pointer variable which point to shell environment variable 
{
i++;
printf("\n env var %d => %s",i,*(env++));
}
printf("\n");
return 0;
}

