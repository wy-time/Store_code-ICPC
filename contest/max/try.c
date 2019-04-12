#include<stdio.h>
#include<string.h>
int main ()
{
    char s[201];
    int i=0,cnt=0,j;
    while(scanf("%s",s)!=EOF)
    {
        cnt=0;
        int a[100];
        char c=s[0];
        int len =strlen(s);
        for(i=0;i<len;i++)
        {
            if((int)c<(int)s[i])
            {
                c=s[i];
            }
        }
        for(i=0;i<len;i++)
        {
            if(s[i]==c)
            {
                a[cnt]=i;
                cnt++;
            }
        }
        j=0;
        for(i=0;i<len;i++)
        {
            printf("%c",s[i]);
            if(i==a[j]&&j<cnt)
            {
                printf("(max)");
                j++;
            }
        }
        printf("\n");
    }
    return 0;
}
