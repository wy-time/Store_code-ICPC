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
const int maxn=1e5+5;
struct node
{
    int id_sum;
    int id_one;
    int a;
    int b;
    int sum;
};
node tree[3][maxn<<2];
struct st
{
    int a;
    int b;
};
st num[maxn];
void push_up(int id,int whi)
{
    if(tree[whi][id<<1].sum<=tree[whi][id<<1|1].sum)
        tree[whi][id].id_sum=tree[whi][id<<1].id_sum;
    else
        tree[whi][id].id_sum=tree[whi][id<<1|1].id_sum;
    tree[whi][id].sum=min(tree[whi][id<<1].sum,tree[whi][id<<1|1].sum);
    tree[whi][id].b=min(tree[whi][id<<1].b,tree[whi][id<<1|1].b);
    if(tree[whi][id<<1].b!=tree[whi][id<<1|1].b)
    {
        if(tree[whi][id<<1].b<tree[whi][id<<1|1].b)
        {
            tree[whi][id].a=tree[whi][id<<1].a;
            tree[whi][id].id_one=tree[whi][id<<1].id_one;
        }
        else
        {
            tree[whi][id].a=tree[whi][id<<1|1].a;
            tree[whi][id].id_one=tree[whi][id<<1|1].id_one;
        }
    }else
    {
        tree[whi][id].a=min(tree[whi][id<<1].a,tree[whi][id<<1|1].a);
        if(tree[whi][id<<1].a<=tree[whi][id<<1|1].a)
            tree[whi][id].id_one=tree[whi][id<<1].id_one;
        else
            tree[whi][id].id_one=tree[whi][id<<1|1].id_one;
    }
}
void build(int id,int l,int r,int whi)
{
    if(l==r)
    {
        tree[whi][id].id_sum=l;
        tree[whi][id].id_one=l;
        tree[whi][id].a=num[l].a;
        tree[whi][id].b=num[l].b;
        tree[whi][id].sum=num[l].a+num[l].b;
        return ;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid,whi);
    build(id<<1|1,mid+1,r,whi);
    push_up(id,whi);
}
void update(int id,int l,int r,int pos,int flag,int whi)
{
    if(l==r)
    {
        if(flag==2)
        {
            tree[whi][id].a=100000;
            tree[whi][id].b=100000;
            tree[whi][id].sum=200000;
            return ;
        }else
        {
            tree[whi][id].b=tree[whi][id].a;
            tree[whi][id].a=100000;
            tree[whi][id].sum=tree[whi][id].b+tree[whi][id].a;
            return ;
        }
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        update(id<<1,l,mid,pos,flag,whi);
    else
        update(id<<1|1,mid+1,r,pos,flag,whi);
    push_up(id,whi);
}
struct st2
{
    int ans;
    int treeid;
    int op;
};
st2 ans[2*maxn];
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
        memset(ans,0,sizeof(ans));
        int n;
        cin>>n;
        int i;
        wfor(i,1,n+1)
        {
            cin>>num[i].a>>num[i].b;
            ans[2*n].ans+=num[i].a+num[i].b;
            ans[2*n].treeid=0;
        }
        build(1,1,n,0);
        build(1,1,n,1);
        build(1,1,n,2);
        ans[2*n-1].ans=ans[2*n].ans-tree[ans[2*n].treeid][1].b;
        ans[2*n-1].treeid=ans[2*n].treeid;
        ans[2*n-1].op=1;
        ans[2*n].treeid=1;
        update(1,1,n,tree[ans[2*n].treeid][1].id_one,1,0);
        mfor(i,2*n-2,1)
        {
            int temp1=ans[i+1].ans-tree[ans[i+1].treeid][1].b;
            int temp2=ans[i+2].ans-tree[ans[i+2].treeid][1].sum;
            if(temp1>=temp2)
            {
                ans[i].ans=temp1;
                ans[i].treeid=ans[i+1].treeid;
                ans[i].op=1;
                update(1,1,n,tree[ans[i+1].treeid][1].id_one,1,ans[i+1].treeid);
                if(ans[i+1].op==1)
                {
                    ans[i+1].treeid=ans[i+2].treeid;
                    update(1,1,n,tree[ans[i+1].treeid][1].id_one,1,ans[i+1].treeid);
                    //if(i+2!=2*n)
                    //{
                    //    if(ans[i+2].op==1)
                    //    {
                    //        ans[i+2].treeid=ans[i+3].treeid;
                    //        update(1,1,n,tree[ans[i+2].treeid][1].id_one,1,ans[i+2].treeid);
                    //    }else
                    //    {
                    //        ans[i+2].treeid=ans[i+4].treeid;
                    //        update(1,1,n,tree[ans[i+2].treeid][1].id_sum,2,ans[i+2].treeid);
                    //    }
                    //}else
                    //    ans[i+2].treeid=2;
                }
                else
                {
                    ans[i+1].treeid=ans[i+3].treeid;
                    update(1,1,n,tree[ans[i+1].treeid][1].id_sum,2,ans[i+1].treeid);
                    //if(i+3!=2*n)
                    //{
                    //    if(ans[i+3].op==1)
                    //    {
                    //        ans[i+3].treeid=ans[i+4].treeid;
                    //        update(1,1,n,tree[ans[i+3].treeid][1].id_one,1,ans[i+3].treeid);
                    //    }else
                    //    {
                    //        ans[i+3].treeid=ans[i+5].treeid;
                    //        update(1,1,n,tree[ans[i+3].treeid][1].id_sum,2,ans[i+3].treeid);
                    //    }
                    //}else
                    //    ans[i+3].treeid=2;
                        
                }
            }else
            {
                ans[i].ans=temp2;
                ans[i].treeid=ans[i+2].treeid;
                ans[i].op=2;
                update(1,1,n,tree[ans[i].treeid][1].id_sum,2,ans[i].treeid);
                if(i+2!=n)
                {
                    if(ans[i+2].op==1)
                    {
                        ans[i+2].treeid=ans[i+3].treeid;
                        update(1,1,n,tree[ans[i+2].treeid][1].id_one,1,ans[i+2].treeid);
                    }
                    else
                    {
                        ans[i+2].treeid=ans[i+4].treeid;
                        update(1,1,n,tree[ans[i+2].treeid][1].id_sum,2,ans[i+2].treeid);
                    }
                }else
                    ans[i+2].treeid=2;
            }
        }
        wfor(i,1,2*n)
            cout<<ans[i].ans<<" ";
        cout<<ans[i].ans<<endl;
    }
    return 0;
}
