#include <iostream>
#include <algorithm> 
#include <map> 
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
const int maxn =8005;
int tree[maxn<<2];
int target[maxn<<2];
void push_down(int id)
{
    if(target[id])
    {
        tree[id<<1]=tree[id<<1|1]=target[id];
        target[id<<1]=target[id<<1|1]=target[id];
        target[id]=0;
    }
}
void updata(int l,int r,int L,int R,int id,int number)
{
    if(l>=L&&r<=R)
    {
        tree[id]=number;
        target[id]=number;
        return ;
    }
    push_down(id);
    int mid=(l+r)>>1;
    if(mid>=L)
        updata(l,mid,L,R,id<<1,number);
    if(mid<R)
        updata(mid+1,r,L,R,id<<1|1,number);
}
int query(int l,int r,int id,int pos)
{
    if(l==r)
    {
        return tree[id];
    }
    push_down(id);
    int ans=0;
    int mid=(l+r)>>1;
    if(mid>=pos)
        ans=query(l,mid,id<<1,pos);
    else
        ans=query(mid+1,r,id<<1|1,pos);
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
    while(cin>>n)
    {
        memset(tree,0,sizeof(tree));
        int i;
        map<int,int>ma;
        int maxnum=0;
        wfor(i,0,n)
        {
            int l,r,id;
            cin>>l>>r>>id;
            l++;
            id++;
            maxnum=max(maxnum,r);
            updata(1,8002,l,r,1,id);
        }
        int last=0;
        wfor(i,1,maxnum+1)
        {
            int tem=query(1,8002,1,i);
            if(tem==0)
            {
                last=0;
                continue;
            }
            if(tem!=last)
            {
                if(ma.count(tem-1)==0)
                    ma.insert(make_pair(tem-1,1));
                else
                    ma[tem-1]++;
                last=tem;
            }
        }
        map<int,int>::iterator it;
        for(it=ma.begin();it!=ma.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
    }
    return 0;
}
