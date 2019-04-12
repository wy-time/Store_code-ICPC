#include<stdio.h>
#include<math.h>
int isprime(int a);
int main ()
{
    int i;
    for(i=3;i<100;i++)
    {
        if(isprime(i))
        {
            if(isprime(i+2))
            {
                printf("%4d/%d",i,i+2);
            }
        }
    }
    return 0;
}
int isprime(int a)
{
    int i,p;
    p=1;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            p=0;
        }
    }
    return p;
}
