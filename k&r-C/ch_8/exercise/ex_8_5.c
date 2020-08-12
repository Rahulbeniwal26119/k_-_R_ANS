#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#undef __S_IFMT
#define __S_IFMT 0160000
// #include <sys/dir.h>
#define MAX_PATH 1024 // maximum path name
extern int stat (const char *,
		 struct stat *);
void dirwalk(char *name, void (*fcn)(char *));
void fsize(char *);
#define NAME_MAX 100
typedef struct
{
    long ino;
    char name[NAME_MAX + 1];
} Dirent;
typedef struct
{
    int fd;
    Dirent d;
} DIR;
DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);
int main(int argc, char *argv[])
{
    if (argc == 1)
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}
void fsize(char *name)
{
    struct stat stbuf;
    if (stat(name, &stbuf) == -1)
    {
        fprintf(stderr, "fsize: cannot access %s\n", name);
       return;
    }
    if ((stbuf.st_mode & __S_IFMT) == __S_IFDIR)
    {
        dirwalk(name, fsize);
    printf("%5lu %6o %3lu %8ld %s\n", stbuf.st_ino , stbuf.st_mode , stbuf.st_nlink , stbuf.st_size , name);
    }
}
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    Dirent *dp;
    DIR *dfd;
    if ((dfd = opendir(dir)) == NULL)
    {
        fprintf(stderr, "dirwalk: cannot open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL)
    {
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
                continue;
        if ((strlen(dir) + strlen(dp->name) + 2) > sizeof(name))
            fprintf(stderr, "dirwalk:name %s/%stoo long\n", dir, dp->name);
        else
        {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}
DIR *opendir(char *name)
{
    int fd;
    struct stat stbuf;
    DIR *dp;
    if ((fd = open(name, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 || (stbuf.st_mode & __S_IFMT) != __S_IFDIR || (dp = (DIR *)malloc(sizeof(DIR))) == NULL)
    {
        return NULL;
    }
    dp->fd = fd;
    return dp;
}
void closedir(DIR *dp)
{
    if (dp)
    {
        close(dp->fd);
        free(dp);
    }
}
#ifndef DIRSIZ
#define DIRSIZ 14
#endif
struct direct
{
    ino_t d_ino;
    char d_name[DIRSIZ];
};
Dirent *readdir(DIR *dp)
{
    struct direct dirbuf;
    static Dirent d;
    while( read(dp->fd , (char *) &dirbuf , sizeof(dirbuf)) == sizeof(dirbuf))
    {
        if(dirbuf.d_ino==0)  //slot not in use
        {
            continue;
        }
         printf("in readdir");
        d.ino = dirbuf.d_ino;
        strncpy(d.name , dirbuf.d_name , DIRSIZ);
        d.name[DIRSIZ]='\0';
        return &d;
    }
    return NULL;
}