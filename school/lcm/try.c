#include<stdio.h>
int Lcm(int a, int b);
int main ()
{
    printf("Input a,b:");
    int a,b,c;
    scanf("%d,%d",&a,&b);
    c=Lcm(a,b);
    if(c==-1)
    {
        printf("Input error!\n");
    }else
        printf("Least Common Multiple of %d and %d is %d\n",a,b,c);
    return 0;
}
int Lcm(int a, int b)
{
    int c;
    int t=a*b;
    if(a<0||b<0)
        return -1;
    else
    {
        if(a<b)
        {
            c=a;
            a=b;
            b=c;
        }
        c=a%b;
        while(c!=0)
        {
            a=b;
            b=c;
            c=a%b;
        }
        return t/b;
    }
}
