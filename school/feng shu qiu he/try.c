#include<stdio.h>
double sum(int n);
int main ()
{
    int n;
    printf("������n��ֵ��\n");
    scanf("%d",&n);
    double b=sum(n);
    printf("n��֮��Ϊ��%f\n",b);
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
