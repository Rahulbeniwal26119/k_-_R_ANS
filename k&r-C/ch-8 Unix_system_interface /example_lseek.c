//
// Created by rahul on 31/7/19.
//
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int get(int fd,long pos,char *buf,int n)
{
    if(lseek(fd,pos,0)>=0)
        return read(fd,buf,n);
    else
        return -1;
}
int main(int argc,char **argv)
{
    int fd;
    fd=open(argv[1],O_RDONLY,0);
    char buf[BUFSIZ];
    int n=6;
    write(fd,buf,get(fd,10,buf,10));
}