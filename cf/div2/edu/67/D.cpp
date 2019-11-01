#include <iostream>
#include <vector> 
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
const int maxn=3e5+5;
int A[maxn];
int B[maxn];
vector<int>pos[maxn];
int tree[maxn<<2];
int cnt[maxn];
void push_up(int id)
{
    tree[id]=max(tree[id<<1],tree[id<<1|1]);
}
void build(int l,int r,int id)
{
    if(l==r)
    {
        tree[id]=B[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    push_up(id);
}
void update(int l,int r,int id,int pos)
{
    if(l==r)
    {
        tree[id]=0;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        update(l,mid,id<<1,pos);
    else
        update(mid+1,r,id<<1|1,pos);
    push_up(id);
}
int query(int l,int r,int id,int L,int R)
{
    if(l>=L&&r<=R)
    {
        return tree[id];
    }
    int ans=0;
    int mid=(l+r)>>1;
    if(L<=mid)
        ans=max(ans,query(l,mid,id<<1,L,R));
    if(R>mid)
        ans=max(ans,query(mid+1,r,id<<1|1,L,R));
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
    int n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int i;
        wfor(i,1,n+1)
        {
            cin>>A[i];
            pos[i].clear();
            cnt[i]=0;
        }
        wfor(i,1,n+1)
        {
            cin>>B[i];
            pos[B[i]].push_back(i);
        }
        build(1,n,1);
        int j=1;i=1;
        int flag=1;
        while(i<=n)
        {
            if(B[j]==0)
            {
                j++;
                continue;
            }
            if(A[i]==B[j])
                j++;
            else
            {
                if(pos[A[i]].size()>cnt[A[i]])
                {
                    int needpos=pos[A[i]][cnt[A[i]]];
                    int maxnum=query(1,n,1,j,needpos-1);
                    if(maxnum<A[i])
                    {
                        update(1,n,1,needpos);
                        B[needpos]=0;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }else
                {
                    flag=0;
                    break;
                }
            }
            cnt[A[i]]++;
            i++;
        }
    if(flag==0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    }
    return 0;
}
