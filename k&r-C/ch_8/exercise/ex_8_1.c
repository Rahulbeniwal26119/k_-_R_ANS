#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#define MAXSIZ 100
void error(char *fmt, ...);
int main(int argc, char *argv[])
{
    int fd;
    void filecopy(int ifd, int ofd);
    if (argc == 1)
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY , 0)) == -1)
                error("cat : cannot open the file %s", *argv);
            else
            {
                filecopy(fd, 1);
                close(fd);
            }
    return 0;
}
void filecopy(int ifd , int ofd)
{
    int n;
    char buf[MAXSIZ];
    while((n=read(ifd , buf , MAXSIZ)) > 0)
        if(write(ofd , buf  , n)!=n)
            error("cat : write error");
}
void error(char *fmt , ...)
{
    va_list  ap;
    va_start(ap , fmt);
    fprintf(stderr , "error:");
    vfprintf(stderr , fmt , ap);
    fprintf(stderr , "\n");
    va_end(ap);
    exit(1);
}

// this is twice fast as the past because standard 
//lib equivalent are make by these 
