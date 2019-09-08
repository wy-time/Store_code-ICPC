#include <iostream>
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
const int maxn=1e5+5;
struct node
{
    int bit[25];
    int tag_xor;
    int tag_or;
    int tag_and;
};
node tree[maxn<<2];
int num[maxn];
void push_up(int id)
{
    int i;
    wfor(i,0,25)
        tree[id].bit[i]=tree[id<<1].bit[i]+tree[id<<1|1].bit[i];
}
void build(int l,int r,int id)
{
    if(l==r)
    {
        int i;
        wfor(i,0,25)
        {
            if((num[l]>>i)&1)
                tree[id].bit[i]=1;
            else
                tree[id].bit[i]=0;
            tree[id].tag_xor=0;
            tree[id].tag_or=0;
            tree[id].tag_and=1;
        }
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    push_up(id);
}
void push_down(int id,int l,int r)
{
    tree[id<<1].tag_and&=tree[id].tag_and;
    tree[id<<1|1].tag_and&=tree[id].tag_and;
    tree[id<<1].tag_or|=tree[id].tag_or;
    tree[id<<1|1].tag_or|=tree[id].tag_or;
    tree[id<<1].tag_xor^=tree[id].tag_xor;
    tree[id<<1|1].tag_xor^=tree[id].tag_xor;
    int i;
    int number=tree[id].tag_xor;
    int mid=(l+r)>>1;
    wfor(i,0,25)
    {
        if((number>>i)&1)
        {
            tree[id<<1].bit[i]=mid-l+1-tree[id<<1].bit[i];
            tree[id<<1|1].bit[i]=r-mid-tree[id<<1|1].bit[i];
        }
    }
    number=tree[id].tag_or;
    wfor(i,0,25)
    {
        if((number>>i)&1)
        {
            tree[id<<1].bit[i]=mid-l+1;
            tree[id<<1|1].bit[i]=r-mid;
        }
    }
    number=tree[id].tag_and;
    wfor(i,0,25)
    {
        if(((number>>i)&i))
        {
            tree[id<<1].bit[i]=0;
            tree[id<<1|1].bit[i]=0;
        }
    }
    tree[id].tag_or=tree[id].tag_xor=0;
    tree[id].tag_and=1;
}
void update(int l,int r,int L,int R,int id,int number,int op)
{
    if(l>=L&&r<=R)
    {
        int i;
        if(op==1)
        {
            tree[id].tag_xor^=number;
            wfor(i,0,25)
            {
                if((number>>i)&1)
                {
                    tree[id].bit[i]=r-l+1-tree[id].bit[i];
                }
            }
        }else if(op==2)
        {
            tree[id].tag_or|=number;
            wfor(i,0,25)
            {
                if((number>>i)&1)
                {
                    tree[id].bit[i]=r-l+1;
                }
            }
        }else
        {
            tree[id].tag_and&=number;
            wfor(i,0,25)
            {
                if(!((number>>i)&1))
                {
                    tree[id].bit[i]=0;
                }
            }
        }
        return ;
    }
    push_down(id,l,r);
    int mid=(l+r)>>1;
    if(L<=mid)
        update(l,mid,L,R,id<<1,number,op);
    if(R>mid)
        update(r,mid+1,L,R,id<<1|1,number,op);
    push_up(id);
}
ll query(int l,int r,int L,int R,int id)
{
    if(l>=L&&r<=R)
    {
        ll temp=0;
        int i;
        wfor(i,0,25)
        {
            temp+=((ll)tree[id].bit[i]<<i);
        }
        return temp;
    }
    ll ans=0;
    push_down(id,l,r);
    int mid=(l+r)>>1;
    if(L<=mid)
        ans+=query(l,mid,L,R,id<<1);
    if(R>mid)
        ans+=query(mid+1,r,L,R,id<<1|1);
    return ans;
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
    int n;
    read(n);
    int i;
    wfor(i,1,n+1)
    {
        //cin>>num[i];
        read(num[i]);
    }
    build(1,n,1);
    int m;
    read(m);
    wfor(i,0,m)
    {
        int op,l,r;
        read(op);
        read(l),read(r);
        if(op==1)
        {
            ll ans=query(1,n,l,r,1);
            printf("%lld\n",ans);
        }else 
        {
            int x;
            cin>>x;
            if(op==2)
                update(1,n,l,r,1,x,1);
            else if(op==3)
                update(1,n,l,r,1,x,2);
            else
                update(1,n,l,r,1,x,3);
        }
    }
    return 0;
}
