#include<stdio.h>
int main ()
{
    int n=1;
    int max=0;
    int cnt=0;
    while(n>0)
    {
        printf("Input score:");
        scanf("%d",&n);
        if(n>max)
        {
            max=n;
        }
        cnt++;
    }
    printf("Total students are %d\n",cnt-1);
    printf("The highest score is %d\n",max);
    return 0;
}
