#include <iostream>
using namespace std;
long long findx(int x,int mode);
void join (int a,int b);
int pre[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    int i;
    cin>>n;
    int t=n;
    for(i=1;i<=n;i++)
    {
        pre[i]=i;
    }
    while(--t)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        join(a,b);
    }
    unsigned long long sum=0;
    for(i=1; i<=n; i++)
    {
        sum+=findx(i,2);
    }
    sum+=n;
    cout<<sum%10000007;
    return 0;
}
long long findx(int x,int mode)
{
    int t=x;
    if(mode==1)
    {
        while(t!=pre[t])
        {
            t=pre[t];
        }
        return t;
    }else
    {
        long long cnt=0;
        while(t!=pre[t])
        {
            t=pre[t];
            cnt++;
        }
        return cnt;
    }
}
void join (int a,int b)
{
    pre[b]=a;
}
