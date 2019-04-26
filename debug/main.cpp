#include <iostream>
#include <cmath> 
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
ll tree[maxn<<2];
ll maxnum[maxn<<2];
ll num[maxn];
void push_up(int id)
{
    maxnum[id]=max(maxnum[id<<1],maxnum[id<<1|1]);
    tree[id]=tree[id<<1]+tree[id<<1|1];
}
void bulid(int l,int r,int id)
{
    if(l==r)
    {
        tree[id]=num[l];
        maxnum[id]=num[l];
        return ;
    }
    int mid=(l+r)>>1;
    bulid(l,mid,id<<1);
    bulid(mid+1,r,id<<1|1);
    push_up(id);
}
void updata(int l,int r,int L,int R,int id)
{
    if(maxnum[id]<=1)
    {
        return ;
    }
    if(l==r)
    {
        tree[id]=sqrt(tree[id]);
        maxnum[id]=tree[id];
        return ;
    }
    int mid=(l+r)>>1;
    if(mid>=L)
        updata(l,mid,L,R,id<<1);
    push_up(id);
    if(mid<R)
        updata(mid+1,r,L,R,id<<1|1);
    push_up(id);
}
ll query(int l,int r,int L,int R,int id)
{
    if(l>=L&&r<=R)
    {
        return tree[id];
    }
    ll ans=0;
    int mid=(l+r)>>1;
    if(mid>=L)
        ans+=query(l,mid,L,R,id<<1);
    if(mid<R)
        ans+=query(mid+1,r,L,R,id<<1|1);
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
    int n;
    int casecnt=0;
    while(cin>>n)
    {
        casecnt++;
        cout<<"Case #"<<casecnt<<":"<<endl;
        int i;
        wfor(i,1,n+1)
        {
            cin>>num[i];
        }
        bulid(1,n,1);
        int m;
        cin>>m;
        wfor(i,0,m)
        {
            int t,l,r;
            cin>>t>>l>>r;
            if(t==0)
            {
                updata(1,n,l,r,1);
            }else
            {
                int ans=query(1,n,l,r,1);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
