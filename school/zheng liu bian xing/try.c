#include<stdlib.h>
#include<stdio.h>
void space (int n);
int main  ()
{
    int n;
    int safe=1;
    printf("Enter length:");
    scanf("%d",&n);
    int i;
    space(n-1);
    int t=n;
    while(t--)
        printf("*");
    space(n-1);
    printf("\n");
    for(i=1;i<n*2-2;i++)
    {
        if(i>n-1)
        {
            if(safe)
            {
                t=n-1;
                safe =0;
            }
            t--;
        }else
        {
            t=i;
        }
        space(abs(n-1-i));
        printf("*");
        space(n+(t-1)*2);
        printf("*");
        printf("\n");
    }
    t=n;
    space(n-1);
    while(t--)
        printf("*");
    space(n-1);
    printf("\n");
    return 0;
}
void space (int n)
{
    while (n--)
    {
        printf(" ");
    }
}
