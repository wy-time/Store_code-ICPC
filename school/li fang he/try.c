#include<stdio.h>
int main ()
{
    int i=0;
    int sum=0;
    for(i=0;sum<1000000;i++)
    {
        sum+=i*i*i;
    }
    printf("%d",i);
    return 0;
}
