#include<stdio.h>
unsigned long Fact(int n);
int main ()
{
    unsigned int n,i;
    unsigned long sum=0;
    printf("Input n(n>0):");
    scanf("%u",&n);
    for(i=1;i<=n;i++)
    {
        sum+=Fact(i);
    }
    printf("sum = %lu\n",sum);
    return 0;
}
unsigned long Fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*Fact(n-1);
}
