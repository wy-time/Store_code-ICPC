#include <iostream>
#include <algorithm> 
#include <queue> 
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
const int maxn=5e4+5;
vector<pair<ll,int>>G[maxn];
struct st
{
    int u;
    ll w;
    int id;
    bool operator <(const st&other)const
    {
        return w>other.w;
    }
};
ll ans[maxn];
int question[maxn];
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        int i;
        wfor(i,0,n+2)
        {
            G[i].clear();
        }
        priority_queue<st>qu;
        wfor(i,0,m)
        {
            int u,v;
            ll w;
            cin>>u>>v>>w;
            G[u].push_back(make_pair(w,v));
        }
        wfor(i,1,n+1)
        {
            sort(G[i].begin(),G[i].end());
            if(G[i].size()>0)
                qu.push({i,G[i][0].first,0});
        }
        int maxnum=0;
        wfor(i,0,q)
        {
            cin>>question[i];
            maxnum=max(maxnum,question[i]);
        }
        int cnt=0;
        while(!qu.empty())
        {
            st temp=qu.top();
            qu.pop();
            ans[++cnt]=temp.w;
            if(cnt>maxnum)
                break;
            if(temp.id+1<G[temp.u].size())
            {
                qu.push({temp.u,temp.w-G[temp.u][temp.id].first+G[temp.u][temp.id+1].first,temp.id+1});
            }
            int v=G[temp.u][temp.id].second;
            if(G[v].size()>0)
                qu.push({v,temp.w+G[v][0].first,0});
        }
        wfor(i,0,q)
        {
            cout<<ans[question[i]]<<endl;
        }
    }
    return 0;
}
