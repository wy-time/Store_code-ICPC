#include<stdio.h>
#include<string.h>
int main ()
{
    char s[100];
    char c[100];
    int t;
    printf("main string:");
    gets(s);
    printf("sub string:");
    gets(c);
    int len =strlen(s);
    printf("site of begining:(<=%d)",len);
    scanf("%d",&t);
    int i;
    printf("After instert:");
    for(i=0;i<t;i++)
    {
        printf("%c",s[i]);
    }
    printf("%s",c);
    for(;i<len;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}
