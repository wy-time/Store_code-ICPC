#include<stdio.h>
#include<math.h>
int IsPrime(int x);
int main ()
{
    int n;
    scanf("%d",&n);
    int i;
    int sum=0;
    for(i=2;i<=n;i++)
    {
        if(IsPrime(i))
        {
            sum+=i;
        }
    }
    printf("%d",sum);
    return 0;
}
int IsPrime(int x)
{
    int i;
    int p=1;
    for(i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            p=0;
            break;
        }
    }
    return p;
}
