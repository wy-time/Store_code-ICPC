#include<stdio.h>
double sum(int n);
int main ()
{
    int n;
    printf("请输入n的值：\n");
    scanf("%d",&n);
    double b=sum(n);
    printf("n项之和为：%f\n",b);
    return 0;
}
double sum(int n)
{
    double t;
    double sum =0;
    double a=2.0,b=1.0;
    while(n--)
    {
        sum+=1.0*a/b;
        t=a;
        a=a+b;
        b=t;
    }
    return sum;
}
