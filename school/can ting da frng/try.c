#include<stdio.h>
int main ()
{
    int n=40;
    int a[11]={0};
    int t;
    int i;
    printf("Input the feedbacks of 40 students:\n");
    while(n--)
    {
        scanf("%d",&t);
        if(t<=0||t>10)
        {
            printf("input error!\n");
        }else
        {
            a[t]++;
        }
    }
    printf("Feedback\tCount\tHistogram\n");
    for(i=1;i<11;i++)
    {
        t=a[i];
        printf("%8d\t%5d\t",i,a[i]);
        while(t--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
