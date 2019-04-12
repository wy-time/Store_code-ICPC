#include<stdio.h>
long long solve (int n);
int main ()
{
    int n;
    scanf("%d",&n);
    long long r=solve(n);
    printf("%lld",r);
    return 0;
}
long long solve (int n)
{
    if(n==1)
        return 1;
    else
        return n*solve(n-1);
}
