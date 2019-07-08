#include <iostream> 
#include <cstring> 
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
const int maxn=205;
const int INF=1e9;
int num[maxn];
int dp[maxn][maxn];
int dp2[maxn][maxn];
int sum[maxn];
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
    int n;
    cin>>n;
    int i;
    wfor(i,1,n+1)
    {
        cin>>num[i];
        num[i+n]=num[i];
    }
    sum[1]=num[1];
    wfor(i,2,2*n+1)
    {
        sum[i]=sum[i-1]+num[i];
    }
    int j,k;
    wfor(i,0,2*n+1)
    {
        wfor(j,0,2*n+1)
        {
            dp2[i][j]=INF;
        }
    }
    int ans1=INF;
    int ans2=0;
    wfor(i,0,2*n+1)
        dp2[i][i]=0;
    wfor(j,2,2*n+1)
    {
        for(i=j-1;i>=1&&j-i<n;i--)
        {
            wfor(k,i,j)
            {
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
                dp2[i][j]=min(dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]);
                ans2=max(ans2,dp[i][j]);
                if(j-i+1==n)
                    ans1=min(ans1,dp2[i][j]);
            }
        }
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
}
