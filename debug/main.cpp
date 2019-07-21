#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn=1e5+5;
int num[maxn];
int dp[105][105];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int n,c;
    cin>>n>>c;
    int i;
    wfor(i,0,n)
    {
        cin>>num[i];
    }
    int ans=1;
    wfor(i,0,c+1)
    {
        if(num[0]==i)
            dp[num[0]][i]=0;
        else
            dp[num[0]][i]=1;
    }
    wfor(i,1,n)
    {
        int j;
        wfor(j,0,c+1)
        {
            if(num[i]==j)
                dp[num[i]][j]=0;
            else
                dp[num[i]][j]=dp[j][num[i]]+1;
            ans=max(ans,dp[num[i]][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
