#include <iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef map<int,int>map1;
map1 dp;
int ans[200005];
int res[200005];
//int len[200005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    for(i=1; i<=n; i++)
    {
        cin>>ans[i];
        dp.insert(make_pair(ans[i],0));
    }
    int cnt=0;
    int low=0;
    int lowpos;
    for(i=1;i<=n;i++)
    {
        int t=ans[i];
        dp[t]=dp[t-1]+1;
        if(dp[t]>cnt)
        {
            cnt=dp[t];
            low=t;
            lowpos=i;
        }
    }
    int j=0;
    for(i=lowpos;i>=0&&low>=1;i--)
    {
        if(ans[i]==low)
        {
            res[j++]=i;
            low--;
        }
    }
    cout<<cnt<<endl;
    j--;
    while(j>0)
    {
        cout<<res[j]<<" ";
        j--;
    }
    cout<<res[j];
    return 0;
}
