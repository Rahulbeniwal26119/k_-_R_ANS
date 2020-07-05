//
// Created by rahul on 17/7/19.
//
#include <stdio.h>
#define min(a,b) ((a)<(b) ? (a) : (b))
#define max(a,b) ((a)>(b) ? (a) : (b))
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
struct rect canonreact(struct rect r)
{
    struct rect temp;
    temp.p1.x=min(r.p1.x,r.p1.x);
    temp.p1.y=min(r.p1.y,r.p2.y);
    temp.p2.x=max(r.p1.x,r.p2.x);
    temp.p2.y=max(r.p1.y,r.p2.y);
    return temp;
}
int main()
{
    struct rect rr={{30,30},{30,30}};
    struct rect rrect=canonreact(rr);
    printf("%d \t %d",rrect.p1.x,rrect.p1.y);
    printf("%d \t %d",rrect.p2.x,rrect.p2.y);
    printf("\t%d ",rrect.p2.y);
}