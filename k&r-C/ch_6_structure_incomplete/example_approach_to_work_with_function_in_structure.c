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
struct point add(struct point pt1, struct point pt2)
{
    pt1.x+=pt2.x;
    pt1.y+=pt2.y;
    return pt1;
}
int ptinrect(struct point p,struct rect r)
{
    return p.x>=r.p1.x && p.x <r.p2.x && p.y >=r.p1.y && p.y < r.p2.y;
}
int main()
{
    struct  rect screen;
    struct point middle;
    screen.p1=makepoint(0,0);
    screen.p2=makepoint(100,100);
    middle=makepoint((screen.p1.x+screen.p2.x)/2,(screen.p1.y+screen.p2.y)/2);
    printf("%d",middle.x);
    printf("%d",screen.p1.y);
struct point np={12,8};
struct point np1={29,9};
struct point npp=add(np,np1);
printf("\n%d\t%d",npp.x,npp.y);
struct point p={1,101};
struct rect r={{0,0},{100,100}};
printf("\nreturn value is  %d",ptinrect(p,r));
}