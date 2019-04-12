#include<stdio.h>
int Gcd(int a, int b);
int main ()
{
    int a,b,r;
    printf("Input a,b:\n");
    scanf("%d,%d",&a,&b);
    if(a<b)
    {
        r=a;
        a=b;
        b=r;
    }
    if(a<=0||b<=0)
    {
        printf("Input number should be positive!\n");
    }
    else
    {
        r=Gcd(a,b);
        printf("MaxCommonFactor = %d\n",r);
    }
    return 0;
}
int Gcd(int a, int b)
{
    return b==0?a:Gcd(b,a%b);
}
