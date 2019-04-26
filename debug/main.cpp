#include <iostream>
#include <stack> 
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
int tree[maxn<<2];
void push_up(int id)
{
    tree[id]=tree[id<<1]+tree[id<<1|1];
}
void updata(int l,int r,int id,int pos,int number)
{
    if(l==r)
    {
        tree[id]=number;
        return ;
    }
    int mid=(l+r)>>1;
    if(mid>=pos)
        updata(l,mid,id<<1,pos,number);
    else
        updata(mid+1,r,id<<1|1,pos,number);
    push_up(id);
}
int flag=0;
void query(int l,int r,int id,int pos,int &x,int &y)
{
    if(flag)
        return;
    if(tree[id]==0)
    {
        return ;
    }
    if(l==r)
    {
        if(tree[id]==1)
        {
            if(l==pos)
            {
                flag=1;
                return ;
            }
            if(l<=pos)
                x=max(x,l);
            else
                y=min(y,l);
        }
        return ;
    }
    int mid=(l+r)>>1;
    if(mid>=x)
        query(l,mid,id<<1,pos,x,y);
    if(mid<y)
        query(mid+1,r,id<<1|1,pos,x,y);
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
    int n,m;
    cin>>n>>m;
    int i;
    stack<int>last;
    wfor(i,0,m)
    {
        char c;
        cin>>c;
        if(c=='D')
        {
            int pos;
            cin>>pos;
            last.push(pos);
            updata(1,n,1,pos,1);
        }else if(c=='Q')
        {
            int pos;
            cin>>pos;
            int x=-1,y=1e9;
            flag=0;
            query(1,n,1,pos,x,y);
            if(flag)
            {
                cout<<0<<endl;
            }else
            {
                int ans=0;
                if(x==-1&&y==1e9)
                {
                    ans=n;
                }else if(x==-1)
                {
                    ans=pos;
                    ans+=y-pos-1;
                }else if(y==1e9)
                {
                    ans=pos-x;
                    ans+=n-pos;
                }else
                {
                    ans+=pos-x;
                    ans+=y-pos-1;
                }
                cout<<ans<<endl;
            }
        }else
        {
            updata(1,n,1,last.top(),0);
            last.pop();
        }
    }
    return 0;
}
