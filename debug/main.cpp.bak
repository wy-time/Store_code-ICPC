#include <iostream>
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
const int maxn=100005;
struct EDGE
{
    int next;
    int end;
};
int head[maxn];
EDGE edge[maxn*2];
int cnt;
void add(int beg,int end)
{
    edge[++cnt].next=head[beg];
    edge[cnt].end=end;
    head[beg]=cnt;
}
int vis[maxn];
int sum[maxn];
int sum_num[maxn];
void dfs(int now)
{
    int i;
    int temp_sum=0;
    int temp_sum_num=0;
    for(i=head[now];i;i=edge[i].next)
    {
        int v=edge[i].end;
        if(!vis[v])
        {
            vis[v]=1;
            dfs(v);
            temp_sum+=sum[v]+1;
            temp_sum_num+=sum_num[v]+sum[v]+1;
        }
    }
    sum_num[now]=temp_sum_num;
    sum[now]=temp_sum;
}
int root_1;
int sum_root1;
int root_2;
int sum_root2;
int find_root(int now,int &root,int &sum_root)
{
    int i;
    int tot=0;
    tot+=sum[now];
    int temp1=sum[now];
    int temp2=sum_num[now];
    for(i=head[now];i;i=edge[i].next)
    {
        int v=edge[i].end;
        if(!vis[v])
        {
            vis[v]=1;
            sum[now]-=(sum[v]+sum_num[v]+1);
            sum_num[now]-=(sum_num[v]+1);
            sum[v]+=sum[now]+sum_num[now]+1;
            sum_num[v]+=sum_num[now]+1;
            if(sum[v]<sum_root)
            {
                sum_root=sum[v];
                root=v;
            }
            tot+=find_root(v,root,sum_root);
            sum[now]=temp1;
            sum_num[now]=temp2;
        }
    }
    return tot;
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
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    vis[1]=1;
    dfs(1);
    root_1=1;
    sum_root1=sum[root_1];
    wfor(i,1,n+1)
    {
        if(!vis[i])
        {
            vis[i]=1;
            root_2=i;
            dfs(i);
            break;
        }
    }
    sum_root2=sum[root_2];
    memset(vis,0,sizeof(vis));
    int ans=0;
    vis[root_1]=1;
    int temp=find_root(root_1,root_1,sum_root1);
    ans+=temp/2;
    vis[root_2]=1;
    temp=find_root(root_2,root_2,sum_root2);
    ans+=temp/2;
    ans+=sum_root2*sum_root1;
    cout<<ans<<endl;
    return 0;
}
