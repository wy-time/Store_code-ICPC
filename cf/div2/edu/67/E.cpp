#include <iostream>
#include <cstring> 
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
vector<int>G[maxn];
int vis[maxn];
ll sum[maxn];
ll ans[maxn];
ll dfs(int now)
{
    vis[now]=1;
    for(auto k:G[now])
    {
        if(!vis[k])
        {
            sum[now]+=dfs(k);
            ans[now]+=ans[k];
        }
    }
    sum[now]+=1;
    ans[now]+=sum[now];
    return sum[now];
}
ll res=0;
void slove(int now)
{
    vis[now]=1;
    res=max(res,ans[now]);
    for(auto k:G[now])
    {
        if(!vis[k])
        {
            ll t1=ans[now];
            ll t2=ans[k];
            ll t3=sum[now];
            ll t4=sum[k];
            ans[now]-=sum[now];
            ans[now]-=ans[k];
            sum[now]-=sum[k];
            ans[now]+=sum[now];
            ans[k]-=sum[k];
            sum[k]+=sum[now];
            ans[k]=ans[k]+ans[now]+sum[k];
            slove(k);
            ans[now]=t1;
            ans[k]=t2;
            sum[now]=t3;
            sum[k]=t4;
        }
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
    wfor(i,0,n-1)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    memset(vis,0,sizeof(vis));
    slove(1);
    cout<<res<<endl;
    return 0;
}
