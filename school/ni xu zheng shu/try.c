#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];
    printf("Enter number:");
    scanf("%s",s);
    int len =strlen(s);
    int i;
    for(i=len-1;i>=0;i--)
    {
        printf("%c",s[i]);
    }
    return 0;
}
