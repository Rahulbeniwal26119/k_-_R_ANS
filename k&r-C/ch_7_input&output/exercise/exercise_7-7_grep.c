//
// Created by rahul on 26/7/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000 //maximum input line length
/*print line that match first argument */
int main(int argc,char **argv)
{
    char pattern[MAXLINE];
    int c,except=0,number=0;
    FILE *fp;
    void fpat(FILE *fp,char *fname,char *pattern,int except,int number);
    while(--argc>0 && (*++argv)[0]=='-')
        while(c=*++argv[0])
            switch(c){
                case 'x':
                    except=1;
                    break;
                case 'n':
                    except=1;
                    break;
                default:
                    printf("find : illegal option%c\n",c);
                    argc=0;
                    break;

            }
    if(argc>=1)
        strcpy(pattern,*argv);
    else
    {
        printf("usage : find[-x][-n] pattern [file...]\n");
        exit(1);
    }
    if(argc==1)
        fpat(stdin,"",pattern,except,number);
    else
        while(--argc>0)  //get a named file
            if((fp=fopen(*++argv,"r"))==NULL)
            {
                fprintf(stderr,"find : cannot open %s\n",*argv);
                exit(1);
            }
            else {
                //name file has been opened
                fpat(fp,*argv,pattern,except,number);
                fclose(fp);
            }
    return 0;



}
void fpat(FILE *fp,char *fname ,char *pattern,int except,int number)
{
    char line[MAXLINE];
    long lineno=0;
    while(fgets(line,MAXLINE,fp)!=NULL){
        ++lineno;
        if((strstr(line,pattern)!=NULL )==except)
        {if(*fname) //have a file name
                printf("%s- ",fname);
            if(number)
                printf("%ld:",lineno);
            printf("%s",line);
        }
    }
}
