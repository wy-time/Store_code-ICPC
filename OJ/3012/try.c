#include<stdio.h>
void get(int *a);
int min(int a,int b);
int max(int a,int b);
void chuli(int*a);
void print(int *a);
int main ()
{
    int a[10];
    get(a);
    return 0;
}
void get(int *a)
{
    int i=0;
    for(i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
    chuli(a);
}
void chuli(int*a)
{
    int *t1,*t2;
    int t;
    t1=&a[0];
    t2=&a[0];
    int i=0;
    for(i=0; i<10; i++)
    {
        if(*t1<a[i])
        {
            t1=&a[i];
        }
        if(*t2>a[i])
        {
            t2=&a[i];
        }
    }
    t=a[0];
    a[0]=*t2;
    *t2=t;
    if(t1==&a[0])
    {
        t1=t2;
    }
    t=a[9];
    a[9]=*t1;
    *t1=t;
    print(a);
}
void print(int*a)
{
    int i=0;
    for(i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }
}
