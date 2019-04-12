#include<stdio.h>
int main ()
{
    int n;
    int a[32]={0};
    int i;
    printf("Input number:");
    scanf("%d",&n);
    int t=n;
    for(i=0;n!=0;i++)
    {
        a[i]=n%2;
        n/=2;
    }
    printf("number of decimal form:%d\n    it\'s binary form: ",t);
    for(i=31;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    return 0;
}
