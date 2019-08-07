#include <iostream>
#include <cstring> 
#include <algorithm> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(ll &x) {
    int flag=0;
    char ch = getchar(); x = 0;
    if(ch=='-')
        flag=1;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
    if(flag)
        x*=-1;
}
const ll maxn=2005;
ll ma[maxn][maxn];
int nex[maxn][maxn];
struct node
{
    ll sum;
    ll sum_L;
    ll sum_R;
    ll sum_tot;
};
struct POll
{
    ll x;
    ll y;
    ll w;
};
POll poll[maxn];
ll x[maxn];
ll y[maxn];
ll num[maxn];
node sum[maxn<<2];
void push_up(int id)
{
    sum[id].sum_tot=sum[id<<1].sum_tot+sum[id<<1|1].sum_tot;
    sum[id].sum=max(sum[id<<1].sum_R+sum[id<<1|1].sum_L,max(sum[id<<1].sum,sum[id<<1|1].sum));
    sum[id].sum_L=max(sum[id<<1].sum_L,sum[id<<1].sum_tot+sum[id<<1|1].sum_L);
    sum[id].sum_R=max(sum[id<<1|1].sum_R,sum[id<<1|1].sum_tot+sum[id<<1].sum_R);
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        if(num[l]>=0)
        {
            sum[id].sum=num[l];
        }else
        {
            sum[id].sum=0;
        }
        sum[id].sum_L=num[l];
        sum[id].sum_R=num[l];
        sum[id].sum_tot=num[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    push_up(id);
}
void update(int id,int l,int r,int pos,int x)
{
    if(l==r)
    {
        if(num[l]+x>=0)
        {
            sum[id].sum+=x;
        }else
        {
            sum[id].sum=0;
        }
        sum[id].sum_L+=x;
        sum[id].sum_R+=x;
        sum[id].sum_tot+=x;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        update(id<<1,l,mid,pos,x);
    else
        update(id<<1|1,mid+1,r,pos,x);
    push_up(id);
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
    ll t;
    read(t);
    while(t--)
    {
        ll n;
        read(n);
        //cin>>n;
        ll i;
        wfor(i,0,n)
        {
            //cin>>poll[i].x>>poll[i].y>>poll[i].w;
            read(poll[i].x);
            read(poll[i].y);
            read(poll[i].w);
            x[i]=poll[i].x;
            y[i]=poll[i].y;
        }
        sort(x,x+n);
        sort(y,y+n);
        ll len=unique(x,x+n)-x;
        ll len2=unique(y,y+n)-y;
        ll j;
        wfor(i,1,len+1)
        {
            wfor(j,1,len2+1)
                ma[i][j]=0;
        }
        wfor(i,0,n)
        {
            ll tx=poll[i].x;
            ll ty=poll[i].y;
            ll pos=lower_bound(x,x+len,tx)-x;
            tx=pos+1;
            pos=lower_bound(y,y+len2,ty)-y;
            ty=pos+1;
            ma[tx][ty]+=poll[i].w;
        }
        wfor(i,1,len+1)
        {
            int lasty=1;
            wfor(j,2,len2+1)
            {
                if(ma[i][j]!=0)
                {
                    nex[i][lasty]=j;
                    lasty=j;
                }
            }
            nex[i][lasty]=j;
        }
        ll ans=0;
        wfor(i,1,len+1)
        {
            memset(num,0,sizeof(num));
            wfor(j,i,len+1)
            {
                int k;
                if(j==i)
                {
                    for(k=1;k<=len2;k=nex[j][k])
                    {
                        num[k]+=ma[j][k];
                    }
                    build(1,1,len2);
                }else
                {
                    for(k=1;k<=len2;k=nex[j][k])
                    {
                        if(ma[j][k]!=0)
                            update(1,1,len2,k,ma[j][k]);
                    }
                }
                ans=max(ans,sum[1].sum);
            }
        }
        printf("%lld\n",ans);
        //cout<<ans<<endl;
    }
    return 0;
}
