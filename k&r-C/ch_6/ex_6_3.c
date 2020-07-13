#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXWORD 100
struct linklist{
    struct linklist *ptr;
    int lnum;
};
struct tnode{
    char *word;
    struct linklist *lines;
    struct tnode *left;
    struct tnode *right;
};
typedef struct tnode treenode;
treenode *addtreex(treenode * , char * , int );
int getword(char * , int );
int noiseword(char *);
void treeprint(treenode*);
int main()
{
    treenode *root;
    char word[MAXWORD];
    int linenum=1;
    root=NULL;
    while(getword(word , MAXWORD) != EOF)
    {
        if(isalpha(word[0]) && noiseword(word)!=-1 )
            root=addtreex(root , word , linenum);
        else if(word[0]=='\n')
            linenum++;
    }
    treeprint(root);
    return 0;
}
treenode *talloc()
{
    return (treenode *) malloc(sizeof(struct tnode));
}
struct linklist *lalloc()
{
    return (struct linklist *)malloc(sizeof(struct linklist));
}
treenode* addtreex(treenode *p , char *w , int linenum)
{
    int cond;
    if(p==NULL)
    {
        p=talloc();
        p->word = strdup(w);
        p->lines=lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w , p->word))==0)
        addln(p , linenum);
    else if((cond = strcmp(w , p->word))<0)
    p->left = addtreex(p->left , w , linenum);
    else 
    p->right = addtreex(p->right , w , linenum);
    return p;
}
void addln(treenode *p , int linenum)
{
    struct linklist *temp;
    temp  = p->lines;
    while(temp->ptr != NULL && temp->lnum !=linenum)
        temp=temp->ptr;
    if(temp->lnum != linenum)
    {
        temp->ptr = lalloc();
        temp->ptr->lnum = linenum;
        temp->ptr->ptr = NULL;
    }
}
void treexprint(treenode *p)
{
    struct linklist *temp;
    if(p!=NULL)
    {
        treexprint(p->left);
        printf("%10s" , p->word);
        for(temp=p->lines;temp!=NULL;temp=temp->lnum)
        {
            printf("%4d" , temp->lnum);
        }
        printf("\n");
        treexprint(p->right);
    }
}
int noiseword(char *w)
{
    char *nw[]={
        "a" , "an" , "and" , "are" , "in" , "is" , "of" , "or" , "that" , "the" , "this" , "to"
    };
    int cond , mid;
    int low=0;
    int high=sizeof(nw) / sizeof(char *) -1 ;
    while (low<=high)
    {
        mid=(low+high)/2;
        if((cond=strcmp(w , nw[mid])) < 0)
        {
            high=mid-1;
        }
        else if(cond > 0)
            low=mid+1;
        else 
        return mid;
    }
    return -1;
    
}