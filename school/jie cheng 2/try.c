#include<stdio.h>
int wwy(int n);
double solve(int m,int n);
int main ()
{
    int m,n;
    printf("请输入m,n的值( m>n )：\n");
    scanf("%d %d",&m,&n);
    double p=solve(m,n);
    printf("n项之和为：%f\n",p);
    return 0;
}
double solve(int m,int n)
{
    double p;
    p=wwy(m)/(1.0*(wwy(n)*wwy(m-n)));
    return p;
}
int wwy(int n)
{
    if(n==1)
        return 1;
    else
        return n*wwy(n-1);
}
