#include<stdio.h>
int main ()
{
    int a,b;
    scanf("%d %d",&a,&b);
    double c=1.0*a/b;
    printf("%.2f\n",c);
    int d=c+0.99999999;
    printf("%d\n",d);
    d*=d;
    int cnt=0;
    int i=0;
    int f[10];
    while(d!=0)
    {
        f[i]=d%10;
        i++;
        cnt++;
        d/=10;
    }
    printf("%d\n",cnt);
    printf("%d %d %d",f[2],f[1],f[0]);
    return 0;
}
