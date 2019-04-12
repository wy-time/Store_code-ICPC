#include<stdio.h>
int main ()
{
    printf("\n");
    int i=0,j,cnt,sum;;
    for(i=1;i<1000;i++)
    {
        int a[40]={0};
        cnt =0;
        sum =0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            {
                a[cnt]=j;
                sum+=j;
                cnt++;
            }
        }
        if(sum==i)
        {
            if(i!=6)
            {
                printf("\n");
            }
            printf("%5d\n",i);
            for(j=0;j<cnt;j++)
            {
                printf("%5d",a[j]);
            }
        }
    }
    return 0;
}
