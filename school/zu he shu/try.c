#include<stdio.h>
unsigned long  Fact(unsigned int  n);
int main ()
{
    unsigned int a=1,b;
    int m,n;
    int i=0;
    do
    {
        printf("Input m,k (m>=k>0):");
        scanf("%d,%d",&m,&n);
    }
    while (m<n||n<0);
    b=Fact(n);
    for(i=0; i<n; i++)
    {
        a*=m;
        m--;
    }
    printf("p = %d\n",a/b);
    return 0;
}
unsigned long  Fact(unsigned int  n)
{
    if(n==1)
        return 1;
    else
    {
        return n*Fact(n-1);
    }
}
