#include <iostream>
#include <set> 
#include <cstring> 
#include <algorithm> 
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
struct st
{
    int l;
    int r;
};
st num[maxn];
int temp[maxn*2];
int tree[maxn];
int taget[maxn];
void push_down(int id)
{
    if(taget[id])
    {
        tree[id<<1]=taget[id];
        tree[id<<1|1]=taget[id];
        taget[id<<1]=taget[id<<1|1]=taget[id];
        taget[id]=0;
    }
}
void updata(int l,int r,int L,int R,int number,int id)
{
    if(l>=L&&r<=R)
    {
        tree[id]=number;
        taget[id]=number;
        return ;
    }
    push_down(id);
    int mid=(l+r)>>1;
    if(mid>=L)
        updata(l,mid,L,R,number,id<<1);
    if(mid<R)
        updata(mid+1,r,L,R,number,id<<1|1);
}
int query(int l,int r,int pos,int id)
{
    if(l==r)
    {
        return tree[id];
    }
    push_down(id);
    int mid=(l+r)>>1;
    int ans=0;
    if(mid>=pos)
        ans=query(l,mid,pos,id<<1);
    else
        ans=query(mid+1,r,pos,id<<1|1);
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
        int n;
        cin>>n;
        int i;
        int cnt=0;
        wfor(i,0,n)
        {
            cin>>num[i].l>>num[i].r;
            temp[cnt++]=num[i].l;
            temp[cnt++]=num[i].r;
        }
        sort(temp,temp+cnt);
        unique(temp,temp+cnt);
        wfor(i,0,n)
        {
            num[i].l=lower_bound(temp,temp+cnt,num[i].l)-temp;
            num[i].r=lower_bound(temp,temp+cnt,num[i].r)-temp;
            updata(1,2*n+5,num[i].l+1,num[i].r+1,i+1,1);
        }
        set<int>st;
        wfor(i,1,2*n+5)
        {
            int t=query(1,2*n+5,i,1);
            if(t!=0)
                st.insert(t);
        }
        cout<<st.size()<<endl;
    }
    return 0;
}
