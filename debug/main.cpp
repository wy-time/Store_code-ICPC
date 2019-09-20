#include <iostream>
#include <algorithm> 
#include <vector> 
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
const ll maxn=5e5+5;
ll vis[maxn];
ll vis2[maxn];
vector<ll>pre;
vector<ll>number;
ll sum[maxn];
struct st 
{
    ll cnt;
    ll id;
    bool operator <(const st &other)const
    {
        if(cnt!=other.cnt)
            return cnt<other.cnt;
        else
            return id<other.id;
    }
}num[maxn];
struct node
{
    ll lch;
    ll rch;
    ll cnt;
};
ll root[maxn];
node tree[maxn*40];
ll tree_cnt;
void build_new(ll l,ll r,ll old,ll &now,ll n)
{
    tree[++tree_cnt]=tree[old];
    tree[tree_cnt].cnt++;
    now=tree_cnt;
    if(l==r)return;
    ll mid=(l+r)>>1;
    if(mid>=n)
        build_new(l,mid,tree[old].lch,tree[now].lch,n);
    else
        build_new(mid+1,r,tree[old].rch,tree[now].rch,n);
}
ll query(ll l,ll r,ll root1,ll root2,ll k)
{
    if(l==r)return l;
    ll cnt=tree[tree[root1].lch].cnt-tree[tree[root2].lch].cnt;
    ll mid=(l+r)>>1;
    if(cnt>=k)
        return query(l,mid,tree[root1].lch,tree[root2].lch,k);
    else
        return query(mid+1,r,tree[root1].rch,tree[root2].rch,k-cnt);
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
    ll n,m,q;
    cin>>n>>m>>q;
    ll i;
    wfor(i,0,n)
    {
        ll t;
        cin>>t;
        vis2[t]++;
    }
    wfor(i,0,m)
    {
        ll t=vis2[i+1];
        number.push_back(t);
        vis[t]++;
        num[i].cnt=t;
        num[i].id=i+1;
    }
    sort(num,num+m);
    wfor(i,0,m)
    {
        build_new(1,m,root[i],root[i+1],num[i].id);
    }
    sort(number.begin(),number.end());
    ll len=unique(number.begin(),number.end())-number.begin();
    sum[0]=vis[number[0]];
    wfor(i,1,len)
        sum[i]=sum[i-1]+vis[number[i]];
    if(len!=1)
       pre.push_back(vis[number[0]]*(number[1]-number[0]));
    wfor(i,1,len)
    {
        if(i+1!=len)
           pre.push_back(sum[i]*(number[i+1]-number[i])+pre[i-1]);
    }
    wfor(i,0,q)
    {
        ll year;
        cin>>year;
        year-=n;
        ll ans=0;
        ll temp=lower_bound(pre.begin(),pre.end(),year)-pre.begin();
        if(temp!=len-1)
        {
            if(pre[temp]==year)
            {
                ll t=sum[temp];
                ans=query(1,m,root[t],root[0],t);
            }else
            {
                if(temp>0)
                    year-=pre[temp-1];
                ll t=sum[temp];
                ans=query(1,m,root[t],root[0],(year-1)%t+1);
            }
        }else
        {
            if(pre.size()!=0)
                year-=*pre.rbegin();
            ll t=sum[len-1];
            ans=query(1,m,root[t],root[0],(year-1)%t+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
