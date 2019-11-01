#include <iostream>
#include <vector> 
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
const int maxn=2e5+5;
ll mod=998244353;
vector<int>G[maxn];
//ll dp[maxn];
//int vis[maxn];
ll fac[maxn];
void init()
{
    int i;
    fac[0]=1;
    wfor(i,1,maxn)
    {
        fac[i]=fac[i-1]*i%mod;
    }
}
//void dfs(int now)
//{
//    vis[now]=1;
//    dp[now]=1;
//    for(auto k:G[now])
//    {
//        if(!vis[k])
//        {
//            dfs(k);
//            dp[now]=dp[now]*dp[k]%mod;
//        }
//    }
//    dp[now]=dp[now]*fac[G[now].size()]%mod;
//}
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
    init();
    ll n;
    cin>>n;
    int i;
    wfor(i,0,n-1)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //dfs(1);
    ll ans=n;
    wfor(i,1,n+1)
    {
        ans=ans*fac[G[i].size()]%mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}
