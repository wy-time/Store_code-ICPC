#include<stdio.h>
int sum (int i,int sum);
int main ()
{
    int n;
    int i,j;
    scanf("%d",&n);
    int sum=0;
    int cnt =0;
    for(i=1;i<=(n/2);i++)
    {
        sum=0;
        for(j=i;sum<n;j++)
        {
            sum+=j;
        }
        if(sum==n)
        {
            printf("%d\n",i);
            cnt++;
        }
    }
    if(cnt==0)
    {
        printf("No Solution");
    }
    return 0;
}
int sum (int i,int sum,int n)
{
    sum+=i;
    if(sum>n)
        return 0;
    else
    {
        return sum(i+1,sum,n);
    }
}
