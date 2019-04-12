#include<stdio.h>
#include<string.h>
int main ()
{
    printf("Input a string:");
    char s[100];
    gets(s);
    printf("Input a character:");
    char c;
    c=getchar();
    printf("Results:");
    int i;
    int len =strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]!=c)
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
    return 0;
}
