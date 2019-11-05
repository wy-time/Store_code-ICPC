#include <iostream>
#include <vector> 
#include <algorithm> 
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
const int maxn=2005;
struct City
{
    int x;
    int y;
    int flag;
    ll c;
    ll k;
};
struct EDGE
{
    int flag;
    int _beg;
    int _end;
    //int _next;
    ll w;
    bool operator <(const EDGE &other)const
    {
        return w<other.w;
    }
};
EDGE edge[4002005];
//int head[2005];
City city[maxn];
int cnt=0;
void add(int beg,int b,ll w)
{
    //edge[++cnt]._next=head[beg];
    edge[++cnt]._end=b;
    edge[cnt]._beg=beg;
    edge[cnt].w=w;
    if(beg==0)
        edge[cnt].flag=1;
    //head[beg]=cnt;
}
int root[maxn];
int findx (int x)
{
    int t=x;
    while(root[t]!=t)
    {
        t=root[t];
    }
    int j;
    while(root[x]!=t)
    {
        j=root[x];
        root[x]=t;
        x=j;
    }
    return t;
}
void _add(int a,int b)
{
    int a1=findx(a);
    int b1=findx(b);
    root[b1]=a1;
}
vector<int>base;
vector<pair<int,int>>conn;
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
    wfor(i,1,n+1)
    {
        cin>>city[i].x>>city[i].y;
        city[i].flag=0;
    }
    wfor(i,1,n+1)
    {
        cin>>city[i].c;
    }
    wfor(i,1,n+1)
    {
        cin>>city[i].k;
    }
    wfor(i,1,n+1)
        add(0,i,city[i].c);
    wfor(i,1,n+1)
    {
        int j;
        wfor(j,i+1,n+1)
        {
            ll dis=abs(city[i].x-city[j].x)+abs(city[i].y-city[j].y);
            add(i,j,(city[i].k+city[j].k)*dis);
        }
    }
    wfor(i,1,n+1)
        root[i]=i;
    sort(edge+1,edge+cnt+1);
    ll res=0;
    wfor(i,1,cnt+1)
    {
        int u,v;
        u=edge[i]._beg;
        v=edge[i]._end;
        if(findx(u)!=findx(v))
        {
            _add(u,v);
            if(edge[i].flag==1)
                base.push_back(v);
            else
            {
                conn.push_back(make_pair(u,v));
            }
            res+=edge[i].w;
        }
    }
    cout<<res<<endl;
    cout<<base.size()<<endl;
    for(auto k:base)
        cout<<k<<" ";
    cout<<endl;
    cout<<conn.size()<<endl;
    for(auto k:conn)
        cout<<k.first<<" "<<k.second<<endl;
    return 0;
}
