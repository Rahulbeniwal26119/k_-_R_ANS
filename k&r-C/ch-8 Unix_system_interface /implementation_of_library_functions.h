//
// Created by rahul on 1/8/19.
//
#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
typedef struct _iobuf{
    int cnt; //character left
    char *ptr; //next character position
    char *base; //location of buffer
    int flag; //mode of file acess
    int fd; //file decriptor
}FILE;
extern FILE _iob[OPEN_MAX];
#define stdin (&_iob[0])
#define stdout (& _iob[1])
#define stderr (& _iob[2])
enum _flag{
    _READ = 01; //file open for reading implementation_of_library_functions
    _WRITE = 02;//file open for writing
    _UNBUF = 04; //file is unbuffered
    _EOF = 010; //EOF has occured in this file
    _ERR = 020; //error occured on this file
};
int _fillbuf(FILE *);
int _flush(int ,FILE * );
