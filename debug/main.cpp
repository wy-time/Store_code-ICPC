#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn=1e5+5;
ll tree[maxn<<2];
ll target[maxn<<2];
void push_up(ll id)
{
    tree[id]=tree[id<<1]+tree[id<<1|1];
}
void build(ll l,ll r,ll id)
{
    if(l==r)
    {
        tree[id]=l;
        return ;
    }
    ll mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    push_up(id);
}
void push_down(ll l,ll r,ll id)
{
    if(target[id]!=0)
    {
        ll mid=(l+r)>>1;
        ll fir=target[id];
        ll n=mid-l+1;
        tree[id<<1]=fir*n+(n*n-n)/2;
        target[id<<1]=fir;
        n=r-mid;
        fir=mid+1-l+fir;
        tree[id<<1|1]=fir*n+(n*n-n)/2;
        target[id<<1|1]=fir;
        target[id]=0;
    }
}
void updata(ll l,ll r,ll L,ll R,ll id)
{
    if(l>=L&&r<=R)
    {
        ll n=r-l+1;
        ll fir=l-L+1;
        tree[id]=fir*n+(n*n-n)/2;
        target[id]=fir;
        return;
    }
    ll mid=(l+r)>>1;
    push_down(l,r,id);
    if(mid>=L)
        updata(l,mid,L,R,id<<1);
    if(mid<R)
        updata(mid+1,r,L,R,id<<1|1);
    push_up(id);
}
ll query(ll l,ll r,ll L,ll R,ll id)
{
    if(l>=L&&r<=R)
    {
        return tree[id];
    }
    ll mid=(l+r)>>1;
    push_down(l,r,id);
    ll ans=0;
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
    ll n,m;
    cin>>n>>m;
    ll i;
    build(1,n,1);
    wfor(i,0,m)
    {
        ll op,l,r;
        cin>>op>>l>>r;
        if(op==1)
        {
            updata(1,n,l,r,1);
        }else
        {
            ll ans=query(1,n,l,r,1);
            cout<<ans<<endl;
        }
    }
    return 0;
}
