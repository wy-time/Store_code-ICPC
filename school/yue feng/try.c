#include<stdio.h>
int gcd(int a,int b);
int main ()
{
    int a,b,c=0;
    scanf("%d/%d",&a,&b);
    while(c!=1)
    {
        c=gcd(a,b);
        a/=c;
        b/=c;
    }
    printf("%d/%d",a,b);
    return 0;
}
int gcd(int a,int b)
{
    int t;
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    t=a%b;
    return t==0?b:gcd(b,t);
}
