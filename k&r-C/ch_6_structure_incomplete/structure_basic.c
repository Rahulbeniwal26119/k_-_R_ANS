#include <stdio.h>
#include <math.h>
double sqrt(double);
struct point{
    int x;
    int y;
};
struct rect{
    struct point p1;
    struct point p2;
};
int main()
{
    struct point pt={320,200};
    printf("%d%d\n",pt.x,pt.y);
    double dist,sqrt(double);
    struct rect screen={{100,200},{500,600}};
    printf("%d\n%d\n",screen.p1.y,screen.p1.x);
    printf("%d\n%d\n",screen.p2.y,screen.p2.x);
}