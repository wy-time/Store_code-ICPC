#include<stdio.h>
#include<math.h>
int IsPrime(int x);
int main ()
{
    int n;
    printf("Please input n:");
    scanf("%d",&n);
    int x=IsPrime(n);
    printf("%d\n",x);
    return 0;
}
int IsPrime(int x)
{
    int i=0;
    int j=0;
    int p=1;
    for(i=x+1;;i++)
    {
        p=1;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                p=0;
                break;
            }
        }
        if(p)
        {
            break;
        }
    }
    return i;
}
