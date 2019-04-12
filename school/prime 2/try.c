#include<stdio.h>
#include<math.h>
int Fun(int m);
int main ()
{
    int n;
    printf("Please input a number:\n");
    while(1)
    {
        scanf("%d",&n);
        if(n>1)
            break;
    }
    if(Fun(n))
    {
        printf("%d is a prime number\n",n);
    }
    else
    {
        printf("%d is not a prime number\n",n);
    }
    return 0;
}
int Fun(int m)
{
    int i=0;
    int p=1;
    for(i=2; i<=sqrt(m); i++)
    {
        if(m%i==0)
        {
            p=0;
            break;
        }
    }
    return p;
}
