#include<stdio.h>
double sum(double t);
double sum2(double t);
double sum3(double t);
int main ()
{
    double a, b, c, res1, res2, res3;
    scanf("%lf %lf %lf", &a, &b, &c);
    res1 = sum(a);
    res2 = sum2(b);
    res3 = sum3(c);
    printf("%.2f\n",res1+res2+res3);
    return 0;
}
double sum (double  t)
{
    if(t == 1)
    {
        return 1;
    }
    else
    {
        return (t + sum(t - 1));
    }
}
double  sum2(double  t)
{
    if(t == 1)
    {
        return 1;
    }
    else
    {
        return ((t * t) + sum2(t - 1));
    }
}
double sum3(double t)
{
    if(t == 1)
    {
        return 1;
    }else
    {
        return 1/t+sum3(t-1);
    }
}
