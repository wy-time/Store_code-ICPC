#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double dp[100];
int main()
{
    //std::ios::sync_with_stdio(false);
    int m,n=4;
    scanf("%d",&m);
    int need[5]={0,1,2,3,5};
    int i,j;
    for(i=0;i<100;i++)
    {
        dp[i]=1;
    }
    double a[5];
    for(i=1;i<=4;i++)
        scanf("%lf",&a[i]);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(j>=need[i])
                dp[j]=max(dp[j],dp[j-need[i]]*pow(1+a[i],(double)need[i]));
            /*else
            dp[i][j]=dp[i-1][j];*/
        }
    }
    printf("%.5f",dp[m]);
    return 0;
}
