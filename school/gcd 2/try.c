#include<stdio.h>
int Gcd(int a, int b);
int main ()
{
    int m,n,x;
    printf("Input a,b:\n");
    scanf("%d,%d",&m,&n);
    if(m<n)
    {
        int t=m;
        m=n;
        n=t;
    }
    if(m==0||n==0)
        printf("Input error!\n");
    else
    {
        x=Gcd(m,n);
        if(x==-1)
        {
            printf("Input error!\n");
        }
        else
        {
            printf("Gcd=%d\n",x);
        }
    }

    return 0;
}
int Gcd(int a, int b)
{
    if(a<0||b<0)
        return -1;
    return b == 0 ? a :Gcd(b,a%b);
}
