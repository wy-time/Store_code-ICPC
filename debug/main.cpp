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
const int maxn=10005;
vector<int>G[maxn];
int vis[maxn];
int maching[maxn];
int slove(int beg)
{
    int i;
    int len=G[beg].size();
    wfor(i,0,len)
    {
        int v=G[beg][i];
        if(!vis[v])
        {
            vis[v]=1;
            if(maching[v]==-1||slove(maching[v]))
            {
                maching[v]=beg;
                maching[beg]=v;
                return 1;
            }
        }
    }
    return 0;
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
    int n,m,x,y;
    while(cin>>n>>m>>x>>y)
    {
        int i;
        wfor(i,0,n+1)
            G[i].clear();
        wfor(i,0,m)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v+n);
            G[v+n].push_back(u);
        }
        memset(maching,-1,sizeof(maching));
        int ans=0;
        wfor(i,1,n+1)
        {
            if(maching[i]==-1)
            {
                memset(vis,0,sizeof(vis));
                slove(i);
            }
        }
        memset(vis,0,sizeof(vis));
        wfor(i,1,n+1)
        {
            if(maching[i]!=-1)
            {
                if(!vis[i])
                {
                    ans++;
                    vis[i]=1;
                }
                if(!vis[maching[i]-n])
                {
                    ans++;
                    vis[maching[i]-n]=1;
                }
            }
        }
        wfor(i,0,x)
        {
            int t;
            cin>>t;
            if(maching[t]==-1)
                ans++;
        }
        wfor(i,0,y)
        {
            int t;
            cin>>t;
            if(maching[t]==-1)
                ans++;
        }
        if(ans==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
