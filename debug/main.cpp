#include <iostream>
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
const int maxn=10005;
struct st
{
    int u;
    int v;
    int cost;
};
st edge[maxn];
int pre[105];
int findx(int x)
{
    int t=x;
    while(pre[t]!=t)
    {
        t=pre[t];
    }
    int j;
    while(pre[x]!=t)
    {
        j=pre[x];
        pre[x]=t;
        x=j;
    }
    return t;
}
void add(int x,int y)
{
    int x1=findx(x);
    int y1=findx(y);
    pre[y1]=x1;
}
struct rule
{
    bool operator()(const st &a,const st&b)
    {
        if(a.cost!=b.cost)
            return a.cost<b.cost;
        else
            return a.u<b.u;
    }
};
struct ANS
{
    int u;
    int v;
};
ANS ans[maxn];
struct rule2
{
    bool operator()(const ANS &a,const ANS &b)
    {
        if(a.u!=b.u)
            return a.u<b.u;
        else
            return a.v<b.v;
    }
};
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
        int n;
        cin>>n;
        int i;
        wfor(i,0,n+1)
        {
            pre[i]=i;
        }
        int j;
        int cnt=0;
        wfor(i,0,n)
        {
            wfor(j,0,n)
            {
                int cost;
                cin>>cost;
                if(cost!=0)
                {
                    edge[cnt].u=i+1;
                    edge[cnt].v=j+1;
                    edge[cnt++].cost=cost;
                }
            }
        }
        sort(edge,edge+cnt,rule());
        int anscnt=0;
        wfor(i,0,cnt)
        {
            int u,v;
            u=edge[i].u;
            v=edge[i].v;
            if(findx(u)!=findx(v))
            {
                add(u,v);
                if(u>v)
                    swap(u,v);
                ans[anscnt].u=u;
                ans[anscnt++].v=v;
            }
        }
        int root=pre[1];
        int flag=0;
        wfor(i,1,n+1)
        {
            if(findx(i)!=root)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<-1<<endl;
        }else
        {
            sort(ans,ans+anscnt,rule2());
            wfor(i,0,anscnt-1)
            {
                cout<<ans[i].u<<" "<<ans[i].v<<" ";
            }
            cout<<ans[i].u<<" "<<ans[i].v<<endl;
        }
    }
    return 0;
}
