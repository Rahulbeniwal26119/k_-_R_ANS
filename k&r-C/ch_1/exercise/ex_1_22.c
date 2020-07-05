#include<stdio.h>
#define MAXCOLS 10 
#define TAB 8
char line[MAXCOLS];
int exptab(int pos);  // use for tab conversion to space for spltiing lines frater 
int findblank(int pos);  // use for splliting the lines if size > MAXCOLS  and return position after a blanks 
int newpos(int pos);  // this function rearrange the lines , that is 
// it copies the characters , starting at pos , to the beginning of the line , then 
// return the new position
void printl(int pos); // use for printing characters between 0 and pos-1 
char line[MAXCOLS];
int main()
{
int c, pos;
pos=0;
while((c=getchar())!=EOF)
{
    line[pos]=c;
    if(c=='\t')
    pos=exptab(pos);
    else if(c=='\n')
 {
  printl(pos);
    pos=0;
}
else if (++pos >= MAXCOLS)
{
    pos=findblank(pos);
    printl(pos);
    pos=newpos(pos);
}
}
}
//printl : print line untill pos column 
void printl(int pos)
{
    int i;
    for(i=0;i<pos ; i++)
    putchar(line[i]);
    if(pos>0)
    printf("\n");
}
//exptabs : expands tabs into blanks 
int exptab(int pos)
{
line[pos]=' ';  // tab is atleast one blank 
for(++pos ; pos < MAXCOLS && pos % TAB != 0 ; pos++)
{
    line[pos]=' ';
}
if(pos < MAXCOLS)
return pos;
else 
{
printl(pos);
return 0;
}
}
int findblank(int pos)
{
while(pos > 0  && line[pos] != ' ')
--pos;
if(pos == 0)
    return MAXCOLS;
    else 
    return pos+1;
}
int newpos(int pos)
{
    int i  , j;
    if(pos <= 0 || pos >= MAXCOLS)
    return 0;
    else
    {
        i=0;
        for(j=pos; j < MAXCOLS ; ++j)
        {
        line[i]=line[j];
        ++i; 
    }
    }
    return i;
    
}