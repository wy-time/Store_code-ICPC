#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn=2e6+5;
struct EDGE
{
    int w;
    int next;
    int _end;
    int first;
};
EDGE edge [maxn];
int head[700];
int cnt=-1;
int dft[700];
int pre[700];
void add(int beg,int _end,int w)
{
    edge [++cnt].next=head[beg];
    edge [cnt].first=beg;
    edge [cnt].w=w;
    edge [cnt]._end=_end;
    head[beg]=cnt;
}
int bfs(int beg,int _end)
{
    queue<int>qu;
    qu.push(beg);
    memset(dft,-1,sizeof(dft));
    dft[beg]=0;
    while(!qu.empty())
    {
        int temp=qu.front();
        qu.pop();
        int i;
        for(i=head[temp];i!=-1;i=edge[i].next)
        {
            int v=edge[i]._end;
            if(dft[v]<0&&edge[i].w>0)
            {
                dft[v]=dft[temp]+1;
                qu.push(v);
            }
        }
    }
    return dft[_end];
}
int dfs(int beg,int _end,int flow)
{
    if(beg==_end)
    {
        return flow;
    }
    int i;
    int ans=0;
    for(i=head[beg];i!=-1;i=edge[i].next)
    {
        int v=edge[i]._end;
        if(edge[i].w<=0||dft[v]!=dft[beg]+1)
        {
            continue;
        }
        pre[v]=i;
        int temp=dfs(v,_end,min(edge[i].w,flow-ans));
        ans+=temp;
        edge[i].w-=temp;
        edge[i^1].w+=temp;
    }
    return ans;
}
int dinic(int beg,int _end)
{
    int ans=0;
    while(bfs(beg,_end)!=-1)
    {
        memset(pre,-1,sizeof(pre));
        ans+=dfs(beg,_end,0x7f7f7f7f);
    }
    return ans;
}
int vis[700];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("/home/time/debug//debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int n,f,d;
    while(cin>>n>>f>>d)
    {
        int i;
        cnt=-1;
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        wfor(i,0,n)
        {
            int f,d;
            cin>>f>>d;
            int j;
            wfor(j,0,f)
            {
                int t;
                cin>>t;
                if(!vis[t])
                {
                    add(0,t,1);
                    add(t,0,0);
                    vis[t]=1;
                }
                add(t,i+400,1);
                add(i+400,t,0);
            }
            wfor(j,0,d)
            {
                int t;
                cin>>t;
                if(!vis[t+200])
                {
                    add(650,t+200,0);
                    add(t+200,650,1);
                    vis[t+200]=1;
                }
                add(t+200,i+500,0);
                add(i+500,t+200,1);
            }
            add(i+400,i+500,1);
            add(i+500,i+400,0);
        }
        cout<<dinic(0,650)<<endl;
    }
    return 0;
}
