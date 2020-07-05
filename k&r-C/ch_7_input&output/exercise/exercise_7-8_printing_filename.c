//
// Created by rahul on 26/7/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "../../../../usr/include/stdio.h"

#define MAXBOT 3 //maximum # lines at bottom page
#define MAXHDR 5 //maximum # lines at head of page
#define MAXLINE 100 //maximum size of a one line
#define MAXPAGE 66 //maximum number of lines on a page
/*print: print files each new on a new file*/
int main(int argc,char **argv)
{
    FILE *fp;
    void fileprint(FILE *fp,char *fname);
    if(argc==1)       //no argument print statdard input
        fileprint(stdin,"");
    else
        while(--argc>0)
            if((fp=fopen(*++argv,"r"))==NULL)
            {
                fprintf(stderr,"print: cannot open %s",*argv);
                exit(1);

            }
            else {
                fileprint(fp, *argv);
                fclose(fp);
            }



}
/*fileprint:print file name */
void fileprint(FILE *fp,char *fname)
{
    int lineno,pageno=1;
    char line[MAXLINE];
    int heading(char *fname,int pageno);
    lineno=heading(fname,pageno++);
    while(fgets(line,MAXLINE,fp)!=NULL) {
        if (lineno == 1) {
            fprintf(stdout, "\f");
            lineno = heading(fname, pageno++);
        }
        fputs(line, stdout);
        if (++lineno > MAXPAGE - MAXBOT)
            lineno = 1;
    }
    fprintf(stdout,"\f");  //page eject after the file
}
//heading :: put heading and enough blank lines
int heading(char *fname,int pageno)
{
    int ln=3;
    fprintf(stdout,"\n\n");
    fprintf(stdout,"%s page%d \n",fname,pageno);
    while(ln++ < MAXHDR)
        fprintf(stdout,"\n");
    return ln;
}
