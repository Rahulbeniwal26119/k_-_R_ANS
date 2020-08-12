typedef long Align;
#define NULL ((void *)0)
union header
{
    struct {
        union header *ptr;
        unsigned size;
    }s;
    Align x;
};
typedef union header Header;
Header base;
Header *freep=NULL;
void *malloc(unsigned nbytes)
{
    Header *p  , *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    nunits = (nbytes + sizeof(Header) -1 ) / sizeof(Header) + 1;
    if((prevp=freep)==NULL)
    {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for(p=prevp->s.ptr; ;  prevp=p ,  p= p->s.ptr)
    {
        if(p->s.size >= nunits)
            prevp->s.ptr = p->s.ptr;
        else 
        {
            p->s.size -= nunits;
            p+=p->s.size;
            p->s.size = nunits;
        }
        freep = prevp;
        return (void *)(p+1);
        }
    if(p==freep)
        if((p=morecore(nunits))==NULL)
            return NULL;

}
