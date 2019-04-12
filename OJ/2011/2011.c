#include<stdio.h>
int main ()
{
    int n;
    int i=0;
    int t;
    double a=2,b=1;
    double sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        sum+=a/b;
        t=b;
        b=a;
        a=t+a;
    }
    printf("%.2f\n",sum);
    return 0;
}
