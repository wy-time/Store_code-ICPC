#include<stdio.h>
int main ()
{
    int i=6;
    int n;
    int cnt=0;
    int  a[4]={12};
    int j=0;
    printf("When grow rate is %d%%, the output can be doubled after %d years.\n",i,a[j]);
    for(i=8;i<=12;i+=2)
    {
        cnt=0;
        n=100;
        while(n<200)
        {
            n*=(1+i*1.0/100);
            cnt++;
        }
        j++;
        a[j]=cnt;
        printf("When grow rate is %d%%, the output can be doubled after %d years.\n",i,a[j]);
    }
    return 0;
}
