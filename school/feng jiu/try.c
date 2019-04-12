#include<stdio.h>
void solve(int a,int b,int c);
int main ()
{
    printf("Input Full a,Empty b,c,Get i:");
    int a,b,c,i;
    scanf("%d%d%d%d",&a,&b,&c,&i);
    solve(a,b,c);
    solve(a,c,b);
    return 0;
}
void solve(int a,int b,int c)
{
    int b1=b,c1=c,a1=a;
    b=0,c=0;
    printf("a%d  b%d  c%d\n%4d%4d%4d\n",a1,b1,c1,a,b,c);
    while(a!=6||(b!=6&&c!=6))
    {
        if(b==0)
        {
            if(a>=b1)
            {
                a-=b1;
                b=b1;
                printf("%4d%4d%4d\n",a,b,c);
            }else
            {
                a=0;
                b+=(a1-a);
                printf("%4d%4d%4d\n",a,b,c);
            }
        }
        else if(c==c1)
        {
            if(c1<=(a1-a))
            {
                a+=c1;
                c=0;
                printf("%4d%4d%4d\n",a,b,c);
            }else
            {
                a=a1;
                c-=a1-a;
                printf("%4d%4d%4d\n",a,b,c);
            }
        }
        else
        {
            if(b>=(c1-c))
            {
                b-=(c1-c);
                c=c1;
                printf("%4d%4d%4d\n",a,b,c);
            }else
            {
                c+=b;
                b=0;
                printf("%4d%4d%4d\n",a,b,c);
            }
        }
    }
}
