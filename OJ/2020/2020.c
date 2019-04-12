#include<stdio.h>
int gcd(int a,int b);
int lcm(int a,int b,int c);
int main()
{
    int a,b,c,d;
    scanf("%d %d",&a,&b);
    c=gcd(a,b);
    d=lcm(a,b,c);
    printf("%d %d\n",c,d);
    return 0;
}
int gcd (int a,int b)
{
    int c=a%b;
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
int lcm(int a,int b,int c)
{
    return (a*b/c);
}
