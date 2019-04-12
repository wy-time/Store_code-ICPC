#include<stdio.h>
#include<string.h>
int main ()
{
    int n,m=0;
    int a[4];
    int i=0;
    scanf("%d",&n);
    while (n!=0)
    {
        a[i]=n%10;
        n/=10;
        a[i]+=5;
        i++;
    }
    for(i=3;i>=0;i--)
    {
        m=m*10+a[i]%10;
    }
    i=0;
    memset(a,0,sizeof(a));
    while(m!=0)
    {
        a[i]=m%10;
        m/=10;
        i++;
    }
    for(i=0;i<4;i++)
    {
        m=m*10+a[i];
    }
    printf("%d",m);
    return 0;
}
