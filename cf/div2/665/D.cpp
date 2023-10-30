#include <iostream>
#include <cstring> 
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
const int maxn=1e5+5;
struct EDGE
{
    int _end;
    int next;
};
int head[maxn];
EDGE edge[2*maxn];
int cnt=0;
void add(int a,int b)
{
    edge[++cnt].next=head[a];
    edge[cnt]._end=b;
    head[a]=cnt;
}
bool vis[maxn];
int dfs(priority_queue<ll>&qu_cnt,int beg,int n)
{
    int u=beg;
    vis[u]=true;
    ll t_cnt=1;
    for(int i=head[beg];i;i=edge[i].next)
    {
        int v=edge[i]._end;
        if(!vis[v])
        {
            ll temp=dfs(qu_cnt,v,n);
            t_cnt+=temp;
            qu_cnt.push(temp*(n-temp));
        }
    }
    return t_cnt;
}
int num[60005];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        memset(head,0,sizeof(head));
        memset(vis,0,sizeof(vis));
        priority_queue<ll>qu_cnt;
        int n;
        cin>>n;
        int i;
        wfor(i,0,n-1)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        int m;
        cin>>m;
        priority_queue<ll>qu;
        wfor(i,0,m)
        {
            int k;
            cin>>k;
            qu.push(k);
        }
        i=0;
        if(m>n-1)
        {
            ll tem=qu.top();
            qu.pop();
            while(qu.size()>=n-1)
            {
                tem=tem*qu.top()%1000000007;
                qu.pop();
            }
            num[i++]=tem;
            m=n-1;
        }
        while(!qu.empty())
        {
            num[i++]=qu.top();
            qu.pop();
        }
        i=0;
        dfs(qu_cnt,1,n);
        ll ans=0;
        ll mod=1e9+7;
        while(!qu_cnt.empty())
        {
            ll c=qu_cnt.top()%mod;
            ll c2=1;
            if(i<m)
            {
                c2=num[i];
                i++;
            }
            qu_cnt.pop();
            ans=(ans+c*c2%mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}

