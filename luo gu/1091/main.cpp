#include <iostream>
#include<algorithm>
using namespace std;
int low [105];
int low2[105];
int ans[105];
int c[105];
int d[105];
const int INF=0x7f7f7f;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    fill(low+1,low+1+n,INF);
    for(i=1;i<=n;i++)
    {
        cin>>ans[i];
    }
    int res=1;
    low[1]=ans[1];
    c[1]=1;
    for(i=2;i<=n;i++)
    {
        if(ans[i]>low[res])
        {
            low[++res]=ans[i];
            c[i]=res;
        }
        else
        {
            int pos=lower_bound(low+1,low+1+res,ans[i])-low;
            low[pos]=ans[i];
            c[i]=pos;
        }
    }
    low2[1]=ans[n];
    int res2=1;
    d[n]=1;
    for(i=n-1;i>=1;i--)
    {
        if(ans[i]>low2[res2])
        {
            low2[++res2]=ans[i];
            d[i]=res2;
        }
        else
        {
            int pos=lower_bound(low2+1,low2+1+res2,ans[i])-low2;
            low2[pos]=ans[i];
            d[i]=pos;
        }
    }
    int maxx=-5;
    for(i=1;i<=n;i++)
    {
        if(maxx<c[i]+d[i]-1)
            maxx=c[i]+d[i]-1;
    }
    cout<<n-maxx;
    return 0;
}
