#include <iostream>
#include <vector> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
char ch = getchar(); x = 0;
for (; ch < '0' || ch > '9'; ch = getchar());
for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const int maxn=2e5+5;
struct st 
{
    int end;
    int next;
};
int head[maxn];
st edge[2*maxn];
int cnt;
void add(int beg,int end)
{
    edge[++cnt].next=head[beg];
    edge[cnt].end=end;
    head[beg]=cnt;
}
vector<int>chose;
vector<int>unchose;
int vis[maxn];
void slove(int now,int flag)
{
    if(flag==1)
        chose.push_back(now);
    else
        unchose.push_back(now);
    vis[now]=1;
    int i;
    for(i=head[now];i;i=edge[i].next)
    {
        int v=edge[i].end;
        if(!vis[v])
            slove(v,flag*-1);
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
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
        int n,m;
        //cin>>n>>m;
        read(n);
        read(m);
        int i;
        cnt=0;
        chose.clear();
        unchose.clear();
        wfor(i,0,n+1)
        {
            head[i]=0;
            vis[i]=0;
        }
        wfor(i,0,m)
        {
            int u,v;
            //cin>>u>>v;
            read(u);
            read(v);
            add(u,v);
            add(v,u);
        }
        slove(1,1);
        if(chose.size()<=unchose.size())
        {
            //cout<<chose.size()<<endl;
            printf("%d\n",(int)chose.size());
            for(auto k:chose)
                printf("%d ",k);
                //cout<<k<<" ";
        }else
        {
            printf("%d\n",(int)unchose.size());
            //cout<<unchose.size()<<endl;
            for(auto k:unchose)
                printf("%d ",k);
                //cout<<k<<" ";
        }
        //cout<<endl;
        printf("\n");
    }
    return 0;
}
