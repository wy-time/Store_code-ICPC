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
const int maxn=50005;
int tree[maxn<<2][2];
int num[maxn];
void push_up(int id)
{
    tree[id][0]=max(tree[id<<1][0],tree[id<<1|1][0]);
    tree[id][1]=min(tree[id<<1][1],tree[id<<1|1][1]);
}
void build(int l,int r,int id)
{
    if(l==r)
    {
        tree[id][0]=tree[id][1]=num[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    push_up(id);
}
void query(int l,int r,int L,int R,int id,int &x,int &y)
{
    if(l>=L&&r<=R)
    {
        x=max(x,tree[id][0]);
        y=min(y,tree[id][1]);
        return ;
    }
    int mid=(l+r)>>1;
    if(mid>=L)
        query(l,mid,L,R,id<<1,x,y);
    if(mid<R)
        query(mid+1,r,L,R,id<<1|1,x,y);
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
        int l,r;
        cin>>l>>r;
        int x=0,y=1e8;
        query(1,n,l,r,1,x,y);
        cout<<x-y<<endl;
    }
    return 0;
}
