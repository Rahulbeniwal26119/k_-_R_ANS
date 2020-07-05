#include<fcntl.h>
#include<unistd.h>
#include <stdio.h>
#include<stdarg.h>
#define MAXSIZE 1000
void error(char *,...);
int main(int argc,char **argv)
{
    int fd;
    void filecopy(int ifd,int ofd);
    if(argc==1)
        filecopy(0,1);
    else
        while(--argc>0)
            if((fd=open(argv[1],O_RDONLY,0))==-1)
                error("cat:cannot open %s",argv[1]);
            else {
                filecopy(fd,1);
                close(fd);
            }
    return 0;
}
void error(char *fmt,...)
{
    va_list args;
    va_start(args,fmt);
    fprintf(stderr, "error");
    vfprintf(stderr,fmt,args);
    fprintf(stderr, "\n" );
    va_end(args);
}
void filecopy(int ifd,int ofd)
{
    int n;
    char buf[MAXSIZE];
    while((n=read(ifd,buf,MAXSIZE))>0)
        if(write( ofd,buf,n)!=n)
            error("cat:write erorr");
}
