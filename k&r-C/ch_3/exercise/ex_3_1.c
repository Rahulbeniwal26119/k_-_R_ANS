#include<stdio.h>
int binsearch(int x , int v[] , int n)
{
    int low , high , mid;
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low <= high && x!=v[mid])
    {
        if(x < v[mid])
        high=mid-1;
        else 
        low=mid+1;
        mid=(low+high)/2;
    }
    if(x==v[mid])
    return mid;
    else
    {
        return -1;
    }
}
int main()
{
    int arr[6]={1,2,3,8,9,10};
    printf("%d is position " , binsearch(8 , arr , 6));
}