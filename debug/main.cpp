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
const int maxn=50005;
struct st
{
    int end;
    int next;
};
st edge[maxn];
int head[maxn];
int cnt;
void add(int beg,int end)
{
    edge[++cnt].next=head[beg];
    edge[cnt].end=end;
    head[beg]=cnt;
}
int interval[maxn];
int mapping[maxn];
int init(int beg,int sum)
{
    int i;
    sum++;
    mapping[beg]=sum;
    for(i=head[beg];i;i=edge[i].next)
    {
        int v=edge[i].end;
        sum=init(v,sum);
    }
    interval[mapping[beg]]=sum;
    return sum;
}
int deg[maxn];
int tree[maxn<<2];
int target[maxn<<2];
void push_down(int id)
{
    if(target[id])
    {
        tree[id<<1]=tree[id<<1|1]=target[id];
        target[id<<1]=target[id<<1|1]=target[id];
        target[id]=0;
    }
}
void updata(int l,int r,int L,int R,int id,int number)
{
    if(l>=L&&r<=R)
    {
        tree[id]=number;
        target[id]=number;
        return;
    }
    push_down(id);
    int mid=(l+r)>>1;
    if(mid>=L)
        updata(l,mid,L,R,id<<1,number);
    if(mid<R)
        updata(mid+1,r,L,R,id<<1|1,number);
}
int query(int l,int r,int id,int pos)
{
    if(l==r)
    {
        return tree[id];
    }
    push_down(id);
    int mid=(l+r)>>1;
    int ans=-1;
    if(mid>=pos)
        ans=query(l,mid,id<<1,pos);
    else
        ans=query(mid+1,r,id<<1|1,pos);
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
    int t;
    cin>>t;
    int casecnt=0;
    while(t--)
    {
        casecnt++;
        cout<<"Case #"<<casecnt<<":"<<endl;
        memset(deg,0,sizeof(deg));
        memset(tree,-1,sizeof(tree));
        memset(target,0,sizeof(target));
        memset(head,0,sizeof(head));
        cnt=0;
        int n;
        cin>>n;
        int i;
        wfor(i,0,n-1)
        {
            int u,v;
            cin>>u>>v;
            add(v,u);
            deg[u]++;
        }
        wfor(i,1,n)
        {
            if(deg[i]==0)
            {
                init(i,0);
                break;
            }
        }
        int m;
        cin>>m;
        wfor(i,0,m)
        {
            char c;
            cin>>c;
            if(c=='T')
            {
                int x,y;
                cin>>x>>y;
                int l=mapping[x];
                int r=interval[l];
                updata(1,n,l,r,1,y);
            }else
            {
                int x;
                cin>>x;
                int pos=mapping[x];
                int ans=query(1,n,1,pos);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
