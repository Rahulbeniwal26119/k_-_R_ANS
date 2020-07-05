#include<stdio.h>
 #define swap(t , x , y)  { t _z ; \
 _z=x ; \
  x=y ; \
   y=_z; \
}
int main()
{
    int a=10 , b=20;
    swap(int , a , b);
     printf("%d \t %d" , a  , b);
}