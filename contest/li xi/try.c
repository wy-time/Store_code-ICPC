#include<stdio.h>
int main ()
{
    int t;
    int i;
    double b,c;
    scanf("%d",&t);
    while(t--)
    {
        double a[5];
        for(i=0;i<5;i++)
        {
            scanf("%lf",&a[i]);
        }
        b=a[0]*(1+a[2]/100*100/365);
        b+=a[0]*(a[2]/100*(a[1]-100)/365);
        b=b*(1+a[4]/100);
        c=a[0]*(1+a[3]/100*((a[1]+365)/365));
        printf("%.1f\n%.1f\n",b,c);
    }
    return 0;
}
