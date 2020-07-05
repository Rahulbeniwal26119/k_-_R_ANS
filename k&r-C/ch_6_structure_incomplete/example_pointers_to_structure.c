//
// Created by rahul on 19/7/19.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
int getword(char *,int );         787899
struct key *binsearch(char *,struct key *,int);
main()
{
    char word[ MAXWORD];
    struct key *p;
    while(getword(word,MAXWORD)!=EOF)
        if(isalpha(word[0]))
            if((p=binsearch(word,keytab,NKEYS)))
                p->word++;
      for(p=keytab;p<keytab+NKEYS;p++)
          if(p->count>0)
              printf("%4d%s",p->count,p->word);
          return 0;

}
struct key *binsearch(char *word,struct key *tab,int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (cond = strcmp(word, mid->word) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}
