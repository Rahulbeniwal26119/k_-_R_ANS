#include<stdio.h>
#include<ctype.h>
#define MAXWORD 100
#define NDISTINCT 1000
struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};
struct tnode * addtree(struct tnode * , char *);
int getword(char * , int );
void sortlist(void);
void treestore(struct tnode *);
struct tnode *list[NDISTNICT];
int ntn=0; //number of tree nodes
int main()
{
  struct tnode *root;
  char word[MAXWORD];
  int i;
  root=NULL;
  while((getword(word , NLINES)!=EOF)
  {
    if(isalpha(word[0]))
      root=addtree(root , word);
  }
  treestore(root);
  sortlist();
  for(int i=0; i< ntn ; i++)
    printf("%2d : %20s\n" , list[i]->count , list[i]->word);
  return 0;
}
void treestore(struct tnode *p)
{
  if(p!=NULL)
  {
    treestore(p->left);
    if(ntn < NDISTINCT)
      list[ntn++] = p;
      treestore(p->right);
  }
}
void sortlist() // Shell sortnin reverse order
{
  int gap ,  i , j;
  struct tnode *gap;
  for(gap=ntn/2 ; gap>0 ; gap/2)
  {
    for(i=gap; i< ntn ; i++)
      for(j=i-gap;j>0;j-=gap)
      {
        if((list[j]->count) >= (list[j+gap]->count))
            break;
        temp = list[j];
        list[j]=list[j+gap];
        list[j+gap]=temp;
      }
  }
}

/*
may be important :-
root=addxtree(root , word ,num , &found);
This line might confuse , if may think that it return the address of leaf
node to main but not , it return the address of leaf to it predecesor treenodex
and this cycle continues and first invoked treenodex return root node pointer to
root.
*/
