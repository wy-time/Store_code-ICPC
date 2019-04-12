#include<stdio.h>
int main ()
{
    int a[2]={0};
    a[1]=1;
    int i;
    printf("%4d",1);
    for(i=1;i<12;i++)
    {
        int t=a[1];
        a[1]+=a[0];
        a[0]=t;
        printf("%4d",a[0]+a[1]);
    }
    printf("\nTotal = %d\n",a[0]+a[1]);
    return 0;
}
