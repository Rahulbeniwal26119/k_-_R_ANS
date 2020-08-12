#include <fcntl.h>
#include "lstd.h"
#include <unistd.h>
int fseek(FILE *fp , long offset , int origion)
{
    unsigned nc;   // no of chars to flush 
    long rc = 0;  // return code
    if(fp->flag & _READ)
    {
        if(origion==1) // from current position 
            offset-=fp->cnt;
        rc=lseek(fp->fd , offset , origion);
        fp->cnt = 0;
    }
    else if(fp->flag & _WRITE)
    {
        if((nc=fp->ptr - fp->base) > 0)
            rc=-1;
        if(rc!=-1)
            rc=lseek(fp->fd , offset , origion);
    }
    return (rc==-1) ? -1 : 0;
}
