#include<stdio.h>
#include<limits.h>
int main()
{long c=10l;
c+=1;
printf("%ld" , c);
    printf("signed char min = %d\n",-(char)(((unsigned char)~0 >> 1) ) -1 );
    printf("Singed char max = %d\n" , (char)((unsigned char)~0 >> 1));
    printf("signed short min = %d\n" , -(short)((unsigned short)~0 >> 1) - 1);
    printf("signed short max = %d\n" , (short)((unsigned short) ~0 >> 1));
    printf("signed int min = %d\n" , -(int)(~(unsigned int)0 >> 1) -1 );
    printf("signed int max = %d\n" , (int)(~(unsigned int)0 >> 1) );
    printf("signed long min= %ld\n" , -(long)(~(unsigned long) 0 >> 1) -1 );
    printf("signed long max=%ld\n" , (long)((unsigned long )~0 >> 1));
    printf("unsigned char max = %u\n" , (unsigned char )~0);   
    printf("unsigned short max = %u\n" , (unsigned short) ~0);
    printf("unsigned int max=%u\n" , (unsigned int )~0);
    printf("unsigned long max = %lu\n" , ULONG_MAX);
  /* from standard header */ 
    printf("%d\n" , SHRT_MIN);
    printf("%d\n" , SHRT_MAX);
    printf("%ul\n" , INT_MIN);
    printf("%ul\n" ,INT_MAX);
    printf("%ld\n" , LONG_MIN);
    printf("%ld\n" ,LONG_MAX );
    printf("%u\n" , UCHAR_MAX);
    printf("%u\n" , USHRT_MAX);
    printf("%u\n" , UINT_MAX);
    printf("%lu\n" , ULONG_MAX);
}