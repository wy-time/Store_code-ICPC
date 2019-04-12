#include <iostream>
using namespace std;
long long ans[500005];
int lowbit(int x);
void updata(int k,int r);
long long getsum(int k);
int n;
int main()
{
    std::ios::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    int i;
    int t1=0,t2=0;
    for(i=1;i<=n;i++)
    {
        cin>>t1;
        updata(i,t1-t2);
        t2=t1;//²î·Ö
    }
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            updata(x,k);
            updata(y+1,-k);
        }else
        {
            int k;
            cin>>k;
            long long res1=getsum(k);
            cout<<res1<<endl;
        }
    }
    return 0;
}

int lowbit(int x)
{
    return x&-x;
}
void updata(int k,int r)
{
    int i=k;
    for(i=k;i<=n;i+=lowbit(i))
    {
        ans[i]+=r;
    }
}
long long getsum(int k)
{
    long long res=0;
    for(int i=k;i>0;i-=lowbit(i))
        res+=ans[i];
    return res;
}
