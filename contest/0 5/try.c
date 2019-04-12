#include<stdio.h>
#include<string.h>
int main ()
{
    int n,i,cnt0=0,cnt5=0;
    int *a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            cnt0++;
        }else
        {
            cnt5++;
        }
    }

}
