void strncpy(char *s , char *p , int n)
{
  while((*s++=*p++) && --n);
  *s='\0';
}
void strncat(char *s  , char *p , int n)
{
  while(*++s)
  printf("\n%c\n" , *s);
  while((*s++ = *p++ )&& --n);
  *s='\0';
}
int  strncmp(char *s , char *p , int n)
{
  while((*s==*p) && --n )
  ++s , ++p;
int dif=*s - *p;
  if(dif==0)
  return 0;
  else if(dif < 0)
  return -1;
  else
  return 1;
}
