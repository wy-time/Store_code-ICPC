#include<stdio.h>
#include<math.h>
int isprime(int a);
int main ()
{
    int m,i;
    printf("Input m:");
    scanf("%d",&m);
    if(isprime(m))
        printf("It is a prime number");
    else
    {
        printf("%d = ",m);
        for(i=2;i<=m;i++)
        {
            while(i!=m)
            {
                if(m%i==0)
                {
                    m/=i;
                    printf("%d * ",i);
                }
                else
                    break;
            }
        }
        printf("%d",m);
    }
    return 0;
}
int isprime(int a)
{
    int i;
    int j=1;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            j=0;
            break;
        }
    }
    return j;
}
