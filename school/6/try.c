#include<stdio.h>
int  MaxCommonFactor(int a, int  b);
int main ()
{
    int a,b,c;
    scanf("%d,%d",&a,&b);
    c=MaxCommonFactor(a,b);
    printf("%d",c);
    return 0;
}
int  MaxCommonFactor(int a, int  b)
{
    int c;
    if(a<=0||b<=0)
    {
        return -1;
    }else
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
        return b;
    }
}
