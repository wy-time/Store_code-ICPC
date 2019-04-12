#include<stdlib.h>
#include<stdio.h>
void chuli(int*a,int*b,int m,int n);
int main ()
{
    int *a;
    int *b;
    int n,i,m;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    b=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    chuli(a,b,m,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}
void chuli(int*a,int*b,int m,int n)
{
    int i=0;
    for(i=0;i<m;i++){
        b[i]=a[n-m+i];
    }
    for(;i<n;i++)
    {
        b[i]=a[i-m];
    }
}
