// use for save the space but function calling create overheads
int isupper(char c)
{
if(c>='A' && c<='Z')
	return 1;
else 
	return 0;
}


// use for saving time but takes more space as macros are expended 
// every time when they call

#define isupper(c)  ((c) > 'A' && (c) <= 'Z') ? 1 : 0

/*
char a='c';
isupper(a);
macro expands to 
(('c') >= 'A' && ('c') <='Z') ? 1 : 0

