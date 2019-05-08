#include <iostream>
#include <cstring> 
#include <queue> 
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
struct EDGE
{
    int end;
    int next;
    int w;
};
const int maxn=1500;
int head[maxn];
EDGE edge[100005];
int cnt=-1;
void add(int beg,int end,int w)
{
    edge[++cnt].next=head[beg];
    edge[cnt].end=end;
    edge[cnt].w=w;
    head[beg]=cnt;
}
int dfn[maxn];
int bfs(int beg,int end)
{
    memset(dfn,0,sizeof(dfn));
    queue<int>qu;
    qu.push(beg);
    dfn[beg]=1;
    while(!qu.empty())
    {
        int now=qu.front();
        qu.pop();
        int i;
        for(i=head[now];i!=-1;i=edge[i].next)
        {
            int v=edge[i].end;
            if(!dfn[v]&&edge[i].w>0)
            {
                dfn[v]=dfn[now]+1;
                qu.push(v);
            }
        }
    }
    return dfn[end];
}
int dfs(int beg,int end,int flow)
{
    int i;
    int ans=0;
    if(beg==end)
    {
        return flow;
    }
    for(i=head[beg];i!=-1;i=edge[i].next)
    {
        int v=edge[i].end;
        if(dfn[v]==dfn[beg]+1&&edge[i].w>0)
        {
            int temp=dfs(v,end,min(edge[i].w,flow-ans));
            ans+=temp;
            edge[i].w-=temp;
            edge[i^1].w+=temp;
        }
    }
    if(!ans)dfn[beg]=0;
    return ans;
}
int dinic(int beg,int end)
{
    int ans=0;
    while(bfs(beg,end)!=0)
    {
        ans+=dfs(beg,end,1e9);
    }
    return ans;
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
    int n,d,f;
    while(cin>>n>>f>>d)
    {
        cnt=-1;
        memset(head,-1,sizeof(head));
        int i;
        wfor(i,0,f)
        {
            int t;
            cin>>t;
            add(0,i+1,t);
            add(i+1,0,0);
        }
        wfor(i,0,d)
        {
            int t;
            cin>>t;
            add(1000,i+1+f,0);
            add(i+1+f,1000,t);
        }
        int pos=d+f;
        wfor(i,0,n)
        {
            add(i+1+pos,i+1+pos+205,1);
            add(i+1+pos+205,i+1+pos,0);
        }
        wfor(i,0,n)
        {
            int j;
            wfor(j,0,f)
            {
                char c;
                cin>>c;
                if(c=='Y')
                {
                    add(j+1,i+1+pos,1);
                    add(i+1+pos,j+1,0);
                }
            }
        }
        wfor(i,0,n)
        {
            int j;
            wfor(j,0,d)
            {
                char c;
                cin>>c;
                if(c=='Y')
                {
                    add(j+1+f,i+1+pos+205,0);
                    add(i+1+pos+205,j+1+f,1);
                }
            }
        }
        int ans=dinic(0,1000);
        cout<<ans<<endl;
    }
    return 0;
}
