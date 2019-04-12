#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char id[20];
    char name[30];
    int gread[3];
} student;
int cmp(const void*x,const void*y);
int main ()
{
    student*p;
    int a=0,b=0,c=0;
    int n;
    scanf("%d",&n);
    p=(student*)malloc(sizeof(student)*n);
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%s %s %d %d %d",p[i].id,p[i].name,&p[i].gread[0],&p[i].gread[1],&p[i].gread[2]);
    }
    for(i=0;i<n;i++)
    {
        a+=p[i].gread[0];
        b+=p[i].gread[1];
        c+=p[i].gread[2];
    }
    a/=n;b/=n;c/=n;
    qsort(&p[0],n,sizeof(student),cmp);
    printf("%d %d %d\n",a,b,c);
    printf("%s %s %d %d %d",p[n-1].id,p[n-1].name,p[n-1].gread[0],p[n-1].gread[1],p[n-1].gread[2]);
    return 0;
}
int cmp(const void*x,const void*y)
{
    student*a=(student*)x;
    student*b=(student*)y;
    int sum1=a->gread[0]+a->gread[1]+a->gread[2];
    int sum2=b->gread[0]+b->gread[1]+b->gread[2];
    return(sum1-sum2);
}
