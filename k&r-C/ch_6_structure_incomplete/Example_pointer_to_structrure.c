//
// Created by rahul on 16/7/19.
//
#include <stdio.h>
struct point{
    int x;
    int y;

};
struct point makepoint(int x,int y)
{
    struct point temp;
    temp.x=x;
    temp.y=y;
    return temp;
}
struct rect{
    struct point p1;
    struct point p2;
};
struct ll  {
    int len;
    char str;
}*p;
int main()
{
    struct point *pp;
    struct point origion=makepoint(0,0);
    pp=&origion;
    printf("%d",pp->x);
    printf("%d",(*pp).y);
    struct rect r={{0,00},{100,50}};
    struct rect *rp;
    rp=&r;
    printf("%d",r.p1.x);
    printf("\n%d\n",rp->p1.y);
    printf("%d",(rp->p2).y);
    struct ll pas={0,30};
    struct ll *ppp;
    ppp=&pas;
    printf("%p",ppp);
    printf("\n%d\n",(ppp)->len);
    printf("%p",ppp);
    printf("%d",ppp->str);
}
