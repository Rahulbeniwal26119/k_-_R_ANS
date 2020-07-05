//
// Created by rahul on 26/7/19.
//
/*this version save memory and pottentially more powerful*/
int isupper(char c)
{
    if(c>='A' && c<='Z')
        return 1;
    else
        return 0;
}

#define isupper(c) ((c)>'A' && (c) < 'Z') ? 1 : 0
/*this version save time and uses more space */
//but it is potentially weak because for *p++ store in c and it will increase twice so became use less
