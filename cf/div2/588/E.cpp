#include <iostream>
#include <vector> 
#include <map> 
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
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
const int maxn=1e5+5;
ll val[maxn];
const ll mod=1e9+7;
map<ll,ll>ma[maxn];
vector<int>G[maxn];
ll ans=0;
void dfs(int now,int fa)
{
    for(auto k:ma[fa])
    {
        ma[now][gcd(k.first,val[now])]+=k.second;
    }
    ma[now][val[now]]++;
    for(auto k:ma[now])
        ans=(ans+(k.first*k.second%mod))%mod;
    for(auto k:G[now])
    {
        if(k==fa)continue;
        dfs(k,now);
    }
}
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
    wfor(i,0,n)
    {
        cin>>val[i+1];
    }
    wfor(i,0,n-1)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
