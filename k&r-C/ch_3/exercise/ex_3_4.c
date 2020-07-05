#define abs(x) ((x) < 0 ? -(x) : (x))
void itoa(int n , char s[])
{
    int i ,sign;
    void reverse(char s[]);
    sign=n;
    i=0;
    do
    {
        s[i++]=abs(n%10)+'0';
    } while ((n/=10)!=0);
    if(sign < 0)
    s[i++]='-';
    s[i]='\0';
    reverse(s);
}
/*
in previous version of it we use 
if(sign < 0 )
n=-n; to make n positive but as signed integer range from -(2^(n-1)) to (2^(n-1) -1 ) so largest negative number cannot to converted to positive number 
so we use macro function abs(x) for each particular word 