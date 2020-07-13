#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 100
int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    void filecomp(FILE *, FILE *);
    if (argc != 3)
    {
        fprintf(stderr, "comp: need two file names %s", *argv);
        exit(1);
    }
    else
    {
        if ((f1 = fopen(*++argv, "r")) == NULL)
        {
            fprintf(stderr, "comp cannot open %s", *argv);
            exit(1);
        }
        else if ((f2 = fopen(*++argv, "r")) == NULL)
        {
            fprintf(stderr, "comp: cannot open %s\n", *argv);
        }
        else
        {
            filecomp(f1, f2);
            fclose(f1);
            fclose(f2);
            exit(0);
        }
    }
}
void filecomp(FILE *f1 , FILE *f2)
{
    char line1[MAXLINE] , line2[MAXLINE];
    char *lp1  , *lp2;
    do{
    lp1=fgets(line1 ,MAXLINE , f1); 
    lp2=fgets(line2 , MAXLINE , f2); // fgets return the pointer to starting element of an charcter array if read succesfully else return NULL if character if eof
    if(lp1==line1 && lp2==line2)
    {
        if(strcmp(lp1 , lp2)!=0)
        {
            printf("first differenece in line%s\n" , line1);
            lp1 = lp2 = NULL;
        }
    }
    else if(lp1 != line1 && lp2 == line2)
    {
        printf("End of the first file at line %s\n" , line2);
    }
    else if(lp1==line1 && lp2!=line2)
    {
        printf("end of the file at line %\n" , line1);
    }
    }while(lp1==line1 && lp2==line2);
}
