//
// Created by Rahul on 6/19/2019.
//#include<stdio.h>
void  converter(int   lower ,int   upper , float step);
int main()
{
	converter(0 , 300 , 20);
}
void  converter(lower , upper , step)
	int lower , upper;
	float step;
{
	for(int   i=lower; i<=upper; i+=step)
	{
		float temp = (5.0/9.0)*((float)i- 32);
		printf("%5d\t%5.2f\n" , i ,  temp);
	}
}
