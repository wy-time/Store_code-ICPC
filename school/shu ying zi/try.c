#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int IsPrime(int x);
int main ()
{
    int n;
    printf("Please enter a number:");
    scanf("%d",&n);
    if(IsPrime(n))
    {
        printf("It is a prime number.No divisor!\n");
    }else
    {
        int i;
        for(i=2;i<abs(n);i++)
        {
            if(n%i==0)
            {
                printf("%d\n",i);
            }
        }
    }
}
int IsPrime(int x)
{
    int i;
    int p=1;
    for(i=2;i<sqrt(abs(x));i++)
    {
        if(x%i==0)
        {
            p=0;
            break;
        }
    }
    return p;
}
