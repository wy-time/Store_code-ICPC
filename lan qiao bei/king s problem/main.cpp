#include <iostream>
#include<algorithm>
using namespace std;
int vis [10005];
typedef struct
{
    int a;
    int b;
    int time;
}st;
st road[100005];
int findx(int x);
bool isfight[100005];
void join (int a,int b);
bool cmp(st a,st b);
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++)
    {
        vis[i]=i;
    }
    for(i=0;i<m;i++)
    {
        cin>>road[i].a>>road[i].b>>road[i].time;
    }
    sort(road,road+m,cmp);
    int cnt =0;
    for(i=0;i<m;i++)
    {
        int a=road[i].a;
        int b=road[i].b;
        int tim=road[i].time;
        if(findx(a)!=findx(b))
        {
            if(!isfight[tim])
            {
                cnt++;
                isfight[tim]=true;
            }
            join(a,b);
        }
    }
    cout<<cnt;
    return 0;
}
int findx(int x)
{
    int t=x;
    while(vis[t]!=t)
    {
        t=vis[t];
    }
    int j=x;
    while(vis[j]!=t)
    {
        int i=vis[j];
        vis[j]=t;
        j=i;
    }
    return t;
}
void join (int a,int b)
{
    int a1=findx(a);
    int b1=findx(b);
    vis[b1]=a1;
}
bool cmp(st a,st b)
{
    return a.time>b.time;
}
