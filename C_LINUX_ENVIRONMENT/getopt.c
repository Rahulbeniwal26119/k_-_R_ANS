#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc , char *argv[])
{
/*
syntax of getopt
int getopt(int argc, char *const argv[],const *optstring);
extern char *optarg;
extern int optind,opterr,optopt;

when all the option argument have been proceessed , optind indicate where the remaining arguments can be found at the end of argv array. it is used to remeber how far it got;

if opterr variable is non zero , getopt will print a error message to stderr.
*/
extern int optind,opterror,optopt;
int opt;
while((opt=getopt(argc,argv,":i:x:lr"))!=-1)  // optarg return -1 if no more oprion to proceed and '--' special argument which will cause to stop the scanning of options;
{
switch(opt)
{
case 'i':
printf("myfile %s ",optarg);  // i is prefix before : so it shown it shown it need a instataneour argument 
break;
case 'l':
case 'r':
printf("option: %c\n",opt);
break;
case 'x':
printf("option %c\n",opt);
printf("filename : %s",optarg);  //optarg is extxern char * optarg point to the file which 'i' and 'x' need to be depend 
break;
case ':':
printf("option needs a value\n");  //: is used to show that argument like 'i' and 'x' need a value if : is not used in as a first charcter in optlist of optarg(3 parameter) it will return '?' 
break;
case '?':
printf("unknown option: %c\n",optopt);  // return '?' if not defiened option found
break;
}
}
for(;optind<argc;optind++) //optind is use for untraced argument to be shown 
printf("argument : %s\n",argv[optind]);
}

