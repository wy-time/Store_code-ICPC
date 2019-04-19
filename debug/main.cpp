#include <iostream>
#include <vector> 
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
const int maxn=1005;
int vis[105];
int ma[105][105];
vector<int>G[105];
int ans[105];
int anscnt;
int res=0;
void dfs(int beg,int aim,int step,int pos)
{
    int len=G[beg].size();
    int i;
    if(aim==step)
    {
        res++;
    }
    wfor(i,pos,len)
    {
        int v=G[beg][i];
        if(!vis[v])
        {
            int j;
            int flag=1;
            wfor(j,0,anscnt)
            {
                if(ma[ans[j]][v]==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                ans[anscnt++]=v;
                dfs(beg,aim,step+1,i+1);
                anscnt--;
            }
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
    int t;
    cin>>t;
    while(t--)
    {
        memset(ma,0,sizeof(ma));
        memset(vis,0,sizeof(vis));
        res=0;
        int n,m,s;
        cin>>n>>m>>s;
        int i;
        wfor(i,1,105)
            G[i].clear();
        wfor(i,0,m)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
            ma[u][v]=1;
            ma[v][u]=1;
        }
        wfor(i,1,n+1)
        {
            anscnt=0;
            dfs(i,s-1,0,0);
            vis[i]=1;
        }
        cout<<res<<endl;
    }
    return 0;
}
