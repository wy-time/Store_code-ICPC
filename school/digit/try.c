#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main ()
{
    int r=0;
    printf("Please enter a string:");
    char s[100];
    scanf("%s",s);
    int len =strlen(s);
    int i;
    printf("the result of output:\n");
    for(i=0; i<len; i++)
    {
        if(isdigit(s[i]))
        {
            r*=10;
            r+=s[i]-'0';
            if(isalpha(s[i+1])||s[i+1]=='\0')
            {
                printf("%10d\n",r);
                r=0;
            }

        }
    }
    return 0;
}
