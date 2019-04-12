#include <iostream>
using namespace std;
int dp[20005];
int info[35];
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j;
    int n,v;
    cin>>v>>n;
    for(i=1;i<=n;i++)
    {
        cin>>info[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=v;j>=info[i];j--)
        {
                dp[j]=max(dp[j],dp[j-info[i]]+info[i]);
        }
    }
    cout<<v-dp[v];
    return 0;
}
