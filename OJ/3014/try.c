#include<stdlib.h>
#include<stdio.h>
int main ()
{
    int *a;
    int n=0,i=0;
    int j,cnt=0;
    scanf("%d",&n);
    j=n;
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        a[i]=1;
    }
    for(i=0;j!=1;i++)
    {
        if(a[i]==1)
        {
            cnt++;
            if(cnt%3==0)
            {
                a[i]=0;
                j--;
            }
        }
        if(i==(n-1))
            i=-1;
    }
    for(i=0;i<n;i++)
    {
        if(a[i])
            printf("%d",i+1);
    }
    return 0;
}
