#include <iostream>
using namespace std;
typedef struct
{
    int w;
    int v;
} st;
st tree[105];
int dp[10005][10005];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        fill(dp[0],dp[0]+10005,100000550);
        int n,c;
        cin>>n>>c;
        int i;
        for(i=1; i<=n; i++)
            cin>>tree[i].w>>tree[i].v;
        dp[0][0]=0;
        for(i=1; i<=n; i++)
        {
            for(int j=1; j<10005; j++)
            {
                if(j>=tree[i].v)
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-tree[i].v]+tree[i].w);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        int ans=0;
        for(i=0; i<10005; i++)
        {
            if(dp[n][i]<=c)
                ans=i;

        }
        cout<<ans<<endl;
    }
    return 0;
}
