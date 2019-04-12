#include <iostream>
using namespace std;
int lowbit(int x);
void updata(int k,int value);
long long getsum(int x);
long long c[500005];
int n;
int main()
{
    std::ios::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    int i,t;
    for(i=1;i<=n;i++)
    {
        cin>>t;
        updata(i,t);
    }
    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
            updata(x,y);
        else
        {
            long long res1=getsum(x-1);
            long long res2=getsum(y);
            cout<<res2-res1<<endl;
        }
    }
    return 0;
}

int lowbit(int x)
{
    return x&-x;
}
void updata(int k,int value)
{
    int i=k;
    for(i=k;i<=n;i+=lowbit(i))
    {
        c[i]+=value;
    }
}
long long getsum(int x)
{
    int i;
    long long ans=0;
    for(i=x;i>0;i-=lowbit(i))
    {
        ans+=c[i];
    }
    return ans;
}
