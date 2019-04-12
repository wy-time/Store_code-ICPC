#include<stdio.h>
long Fact(int n);
int main ()
{
    int a,i;
    long sum;
    printf("Input n(n>0):");
    scanf("%d",&a);
    sum=0;
    a=(a*2)-1;
    for(i=1;i<=a;i+=2)
    {
        sum+=Fact(i);
    }
    printf("sum = %ld\n",sum);
    return 0;
}
long Fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*Fact(n-1);
}
