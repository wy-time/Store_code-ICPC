#include <iostream>
#include<algorithm>
using namespace std;
int findx (int x);
void join (int a,int b);
typedef struct
{
    int a;
    int b;
    int vaule;
}st;
st road[200005];
int dork[10005];
bool cmp(st a,st b);
int vis[10006];
bool isdork[10005];
int main()
{
    //std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<10006;i++)
    {
        vis[i]=i;
    }
    for(i=0;i<m;i++)
    {
        cin>>road[i].a>>road[i].b>>road[i].vaule;
    }
    for(i=0;i<n;i++)
    {
        cin>>dork[i];
    }
    int cnt=0;
    sort(road,road+m,cmp);
    int sum1=0,sum2=0;
    for(i=0;i<m;i++)
    {
        int a=road[i].a;
        int b=road[i].b;
        if(findx(a)!=findx(b))
        {
            cnt++;
            if(dork[a-1]!=-1&&dork[b-1]!=-1)
            {
                if(isdork[a-1])
                {
                    if(!isdork[b-1])
                    {
                        if(dork[b-1]<road[i].vaule)
                        {
                            sum1+=dork[b-1];
                            isdork[b-1]=true;
                            join(b,10005);
                        }else
                            sum1+=road[i].vaule;
                    }
                }else if(isdork[b-1])
                {
                    if(dork[a-1]<road[i].vaule)
                    {
                        sum1+=dork[a-1];
                        isdork[a-1]=true;
                        join(a,10005);
                    }else
                        sum1+=road[i].vaule;
                }else
                {
                    if(dork[a-1]+dork[b-1]<road[i].vaule)
                    {
                        sum1+=dork[a-1]+dork[b-1];
                        isdork[a-1]=true;
                        isdork[b-1]=true;
                        join(a,10005);
                    }else
                        sum1+=road[i].vaule;
                }
            }else
                sum1+=road[i].vaule;
            join(a,b);
        }else if(road[i].vaule<0)
            sum1+=road[i].vaule;
    }
    for(i=0;i<10006;i++)
    {
        vis[i]=i;
    }
    int cnt1=m;
    for(i=0;i<n;i++)
    {
        if(dork[i]!=-1)
        {
            road[cnt1].a=10005;
            road[cnt1].b=i+1;
            road[cnt1].vaule=dork[i];
            cnt1++;
        }
    }
    sort(road,road+cnt1,cmp);
    for(i=0;i<cnt1;i++)
    {
        int a=road[i].a;
        int b=road[i].b;
        if(findx(a)!=findx(b))
        {
            join(a,b);
            sum2+=road[i].vaule;
        }else if(road[i].vaule<0)
            sum2+=road[i].vaule;
    }
    int sum=0;
    if(cnt==n-1)
    {
        sum=min(sum1,sum2);
    }else
        sum=sum2;
    cout<<sum;
    return 0;
}
bool cmp(st a,st b)
{
    return a.vaule<b.vaule;
}
int findx (int x)
{
    int f=x;
    while(vis[f]!=f)
    {
        f=vis[f];
    }
    int j=x;
    int i;
    while(vis[j]!=f)
    {
        i=vis[j];
        vis[j]=f;
        j=i;
    }
    return f;
}
void join (int a,int b)
{
    int a1=findx(a);
    int b1=findx(b);
    vis[b1]=a1;
}
