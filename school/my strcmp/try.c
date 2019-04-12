#include<stdio.h>
#include<string.h>
int MyStrcmp(char s[],char t[]);
int main ()
{
    char s[81],t[81];
    printf("Input s\n");
    gets(s);
    printf("Input t\n");
    gets(t);
    int p=MyStrcmp(s,t);
    if(p>0)
        printf("string s>string t.\n");
    else if(p==0)
        printf("string s=string t.\n");
    else
        printf("string s<string t.\n");
    return 0;
}
int MyStrcmp(char s[],char t[])
{
    int i;
    int p=0;
    int lens=strlen(s);
    int lent=strlen(t);
    if(lens>lent)
        return 1;
    else if(lens<lent)
        return -1;
    for(i=0;i<lens;i++)
    {
        if(s[i]!=t[i])
        {
            p=s[i]-t[i];
            break;
        }
    }
    return p;
}
