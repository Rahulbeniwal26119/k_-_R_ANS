//
// Created by rahul on 29/7/19.
//
/*
#include <fcntl.h>
int fd;
fd=open(name,flags,permission);
 * O_RDONLY
 * O_WRONLY
 * O_RDWR
 * fd=open(name,O_RDONLY,0);
 * int cret(char *name,int permission);
 * fd=cret(name,perms);//creat creat a file
 *
 */
#include <stdarg.h>
#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define PERMS 0666
#define MAXSIZE 1000  //RW for owner,usr,group
void error(char *,...);
//cp::copy f1 to f2
int main(int argc,char **argv)
{
    int f1,f2,n;
    char buf[MAXSIZE];
    if(argc!=3)
        error("Usage : cp from to");
    if((f1=open(argv[1],O_RDONLY,0))==-1)
        error("cp:cannot open %s",argv[1]);
    if((f2=creat(argv[2],PERMS))==-1)
        error("cp: cannot create %s,mode %03o",argv[2],PERMS);
    while((n=read(f1,buf,MAXSIZE))>0)
        if(write(f2,buf,n)!=n)
            error("cp:write error on file %s",argv[2]);
    return 0;
}
void error(char *fmt,...)
{
    va_list args;
    va_start(args,fmt);
    fprintf(stderr,"error");
    vfprintf(stderr,fmt,args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}
