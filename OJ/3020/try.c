#include<stdio.h>
int main ()
{
    int a[20];
    int i=0;
    int cnt=0;
    double sum=0;
    for(i=0;i<20;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)
            cnt++;
        if(a[i]>0)
            sum+=a[i];
    }
    sum/=(20-cnt);
    printf("%d\n%.2f",cnt,sum);
    return 0;
}
