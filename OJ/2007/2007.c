#include<stdio.h>
long long dfs (long long a);
int main ()
{
    long long n, sum = 0;
    scanf("%lld", &n);
    while(n--)
    {
        sum += dfs(n + 1);
    }
    printf("%lld\n", sum);
    return 0;
}
long long dfs (long long a)
{
    if(a == 1 || a == 0)
    {
        return 1;
    }
    else
    {
        return((a * dfs(a - 1)));
    }
}
