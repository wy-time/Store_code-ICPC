#include<stdio.h>
#include<string.h>
int main ()
{
    printf("Input a string:\n");
    char s[100];
    gets(s);
    int len =strlen (s);
    int i;
    char c=s[0];
    for (i=0;i<len;i++)
    {
        if(s[i]>c)
        {
            c=s[i];
        }
    }
    printf("The largest character of \"%s\" is \'%c\' ,The ASCII is %d.",s,c,c);
    return 0;
}
