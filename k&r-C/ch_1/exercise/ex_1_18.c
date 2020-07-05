#include<stdio.h>
#define MAXLINE 1000
int getlline(char line[] , int maxline )
{
    int c;
    int len=0;
    while((c=getchar())!=EOF && len < MAXLINE && c!='\n')
    {
        line[len]=c;
        ++len;
    }
    if(c=='\n')
    line[len]='\0';
    return len;
}
int remover(char line[] , int len)
{
    char c;
    int new_len=0;
    int i=0;
    int blank_track=0;
    int final_len=0;
    int is_space=0;
    int is_only_space=0;
    while(line[i]!='\0')
    {
        i++;
        if((line[i]==' ' || line[i]=='\t')  && blank_track==0)
        {
            is_space=1;
            ++blank_track;
        }
        else if(blank_track > 0 && ( line[i]==' ' || line[i]=='\t'))
        {
            ++blank_track;
            if(line[i+1]=='\0')
            final_len = blank_track;
        }
        else
        {
            blank_track=0;
            is_space=0;
        }


    }
    line[len-final_len]='\0';
    printf("%s\n",line);
}
int main()
{
    int len=0;
    char array[MAXLINE];
    while((len=getlline(array , MAXLINE)) > 0)
    remover(array , len);
}
