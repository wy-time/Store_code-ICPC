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
const int maxn=20;
const int mod=1e9+7;
pair<int,int>song[maxn];
const int N=(1<<16)+5;
int sum[N];
ll dp[N][maxn];
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
    int n,t;
    cin>>n>>t;
    int i,j,k;
    wfor(i,0,n)
    {
        cin>>song[i].first>>song[i].second;
    }
    wfor(i,0,1<<n)
    {
        wfor(j,0,n)
        {
            if(1<<j&i)
                sum[i]+=song[j].first;
        }
    }
    ll ans=0;
    wfor(i,0,n)dp[1<<i][i]=1;
    wfor(i,0,1<<n)
    {
        if(sum[i]==t)
        {
            wfor(j,0,n)
            {
                if(1<<j&i)
                    ans=(ans+dp[i][j])%mod;
            }
        }
        wfor(j,0,n)
        {
            if(!(1<<j&i))continue;
            wfor(k,0,n)
            {
                if(!(1<<k&i)&&song[j].second!=song[k].second)dp[i|(1<<k)][k]=(dp[i|(1<<k)][k]+dp[i][j])%mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
