#include <iostream>
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
int num[maxn];
ll tree[maxn<<2];
ll add[maxn<<2];
void push_up(int id)
{
    tree[id]=tree[id<<1]+tree[id<<1|1];
}
void build(int l,int r,int id)
{
    if(l==r)
    {
        tree[id]=num[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    push_up(id);
}
void push_down(int id,int ln,int rn)
{
    if(add[id]!=0)
    {
        tree[id<<1]+=add[id]*(ll)ln;
        tree[id<<1|1]+=add[id]*(ll)rn;
        add[id<<1]+=add[id];
        add[id<<1|1]+=add[id];
        add[id]=0;
    }
}
void update(int l,int r,int L,int R,int id,ll number)
{
    if(l>=L&&r<=R)
    {
        tree[id]+=number*(ll)(r-l+1);
        add[id]+=number;
        return ;
    }
    int mid=(l+r)>>1;
    push_down(id,mid-l+1,r-mid);
    if(mid>=L)
        update(l,mid,L,R,id<<1,number);
    if(mid<R)
        update(mid+1,r,L,R,id<<1|1,number);
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
    push_down(id,mid-l+1,r-mid);
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
    int n,q;
    cin>>n>>q;
    int i;
    wfor(i,1,n+1)
    {
        cin>>num[i];
    }
    build(1,n,1);
    wfor(i,0,q)
    {
        char op;
        cin>>op;
        if(op=='Q')
        {
            int l,r;
            cin>>l>>r;
            ll ans=query(1,n,l,r,1);
            cout<<ans<<endl;
        }else
        {
            int l,r;
            ll number;
            cin>>l>>r>>number;
            update(1,n,l,r,1,number);
        }
    }
    return 0;
}
