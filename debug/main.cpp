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
int tree[maxn<<2];
int add[maxn<<2];
void push_up(int id)
{
    tree[id]=tree[id<<1]+tree[id<<1|1];
}
void push_down(int id)
{
    if(add[id])
    {
        tree[id<<1]=0;
        tree[id<<1|1]=0;
        add[id<<1]=add[id<<1|1]=1;
        add[id]=0;
    }
}
int x,y;
void query(int l,int r,int L,int R,int id,int &sum)
{
    if(sum==0)
        return;
    if(l>=L&&r<=R)
    {
        int emp=r-l+1-tree[id];
        if(emp==0)
            return ;
        x=min(x,r);
        y=max(y,l);
    }
    if(l==r)
    {
        if(tree[id]==0)
        {
            x=min(x,l);
            y=max(y,l);
            sum--;
            tree[id]=1;
        }
        return ;
    }
    int mid=(l+r)>>1;
    push_down(id);
    if(mid>=L)
        query(l,mid,L,R,id<<1,sum);
    if(mid<R)
        query(mid+1,r,L,R,id<<1|1,sum);
    push_up(id);
}
void updata(int l,int r,int L,int R,int id)
{
    if(l>=L&&r<=R)
    {
        tree[id]=0;
        add[id]=1;
        return ;
    }
    int mid=(l+r)>>1;
    push_down(id);
    if(mid>=L)
        updata(l,mid,L,R,id<<1);
    if(mid<R)
        updata(mid+1,r,L,R,id<<1|1);
    push_up(id);
}
int query2(int l,int r,int L,int R,int id)
{
    if(l>=L&&r<=R)
    {
        return tree[id];
    }
    int mid=(l+r)>>1;
    int ans=0;
    push_down(id);
    if(mid>=L)
        ans+=query2(l,mid,L,R,id<<1);
    if(mid<R)
        ans+=query2(mid+1,r,L,R,id<<1|1);
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
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        memset(add,0,sizeof(add));
        int n,m;
        cin>>n>>m;
        int i;
        wfor(i,0,m)
        {
            int op;
            cin>>op;
            if(op==1)
            {
                int pos,num;
                cin>>pos>>num;
                x=1e9;
                y=-1;
                query(1,n,pos+1,n,1,num);
                if(y==-1)
                    cout<<"Can not put any one."<<endl;
                else
                {
                    x--;
                    y--;
                    cout<<x<<" "<<y<<endl;
                }
            }else 
            {
                int l,r;
                cin>>l>>r;
                l++;
                r++;
                int ans=query2(1,n,l,r,1);
                cout<<ans<<endl;
                updata(1,n,l,r,1);
            }
        }
        cout<<endl;
    }
    return 0;
}
