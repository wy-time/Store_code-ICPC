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
    printf("������[%d..%d]���һ��������",n,m);
    a=getint(n,m);
    printf("�����������Ϊ��%d",a);
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
        printf("������[%d..%d]���һ��������",min,max);
    }
}
