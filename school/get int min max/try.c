#include<stdio.h>
int getint(int min, int max);
int main ()
{
    int n,m,t,a;
    n=3;m=100;
    if(n>m)
    {
        t=n;
        n=m;
        m=t;
    }
    printf("请输入[%d..%d]间的一个整数：",n,m);
    a=getint(n,m);
    printf("你输入的整数为：%d",a);
    return 0;
}
int getint(int min, int max)
{
    int a;
    while (1)
    {
        scanf("%d",&a);
        if(a>=min&&a<=max)
        {
            return a;
        }
        printf("请输入[%d..%d]间的一个整数：",min,max);
    }
}
