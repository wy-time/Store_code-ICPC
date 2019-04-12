#include <iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int ans[1005];
ll dp[1005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>ans[i];
    }
    dp[0]=ans[0];
    for(i=1;i<n;i++)
    {
        if(dp[i-1]>0)
            dp[i]=dp[i-1]+ans[i];
        else
            dp[i]=ans[i];
    }
    ll res=0;
    for(i=0;i<n;i++)
    {
        if(dp[i]>res)
            res=dp[i];
    }
    if(res>k)
        cout<<0;
    else
    {
        for(i=0;i<n;i++)
        {
            ans[i]*=-1;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=ans[0];
        for(i=1;i<n;i++)
        {
            if(dp[i-1]>0)
                dp[i]=dp[i-1]+ans[i];
            else
                dp[i]=ans[i];
        }
        ll res2=0;
        for(i=0;i<n;i++)
        {
            if(dp[i]>res2)
                res2=dp[i];
        }
        if(res2>k)
            cout<<0;
        else
        {
            cout<<k-max(res,res2)+1;
        }
    }
    return 0;
}
