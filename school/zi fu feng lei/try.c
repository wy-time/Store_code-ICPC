#include<stdio.h>
#include<ctype.h>
int main ()
{
    char c;
    printf("Enter a charactor:");
    scanf("%c",&c);
    if(isdigit(c))
    {
        printf("\nThe charactor is a digit charactor.\n");
    }else if(isalpha(c))
    {
        if(isupper(c))
        {
            printf("\nThe charactor is a capital charactor.\n");
        }else
        {
            printf("\nThe charactor is a lower charactor.\n");
        }
    }
    else
    {
        printf("\nThe charactor is a other charactor.\n");
    }
    return 0;
}
