#include<stdio.h>
double myPOW(int x,int n);
int main ()
{
    int a,b;
    printf("Enter x and n\n");
    scanf("%d%d",&a,&b);
    double c = myPOW(a,b);
    printf("pow(%d,%d) = %.2f\n",a,b,c);
    return 0;
}
double myPOW(int x,int n)
{
    int i=0;
    double c=1;
    for(i=0;i<n;i++)
    {
        c*=x;
    }
    return c;
}
