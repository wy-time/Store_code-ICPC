#include <iostream>
#include<algorithm>
using namespace std;
int ans[500005];
int low1[500005];
int low2[500005];
int c[500005];
int d[500005];
const int INF=0x3f3f3f;
int n;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    register int i;
    fill(low1+1,low1+n+1,INF);
    fill(low2+1,low2+n+1,INF);
    register int maxx=0;
    for(i=1;i<=n;i++)
    {
        cin>>ans[i];
    }
    register int res=0;
    low1[0]=0;
    for(i=1;i<=n;i++)
    {
        if(ans[i]>=low1[res])
        {
            low1[++res]=ans[i];
            c[i]=res;
        }else
        {
            int pos=upper_bound(low1+1,low1+1+res,ans[i])-low1;
            low1[pos]=ans[i];
            c[i]=pos;
        }
    }
    register int res2;
    res2=0;
    low2[0]=0;
    register int j;
    for(j=n;j>=0;j--)
    {
        if(ans[j]>=low2[res2])
        {
            low2[++res2]=ans[j];
            d[j]=res2;
        }else
        {
            int pos=upper_bound(low2+1,low2+1+res2,ans[j])-low2;
            low2[pos]=ans[j];
            d[j]=pos;
        }
    }
    for(i=1;i<=n;i++)
    {
        maxx=max(d[i]+c[i]-1,maxx);
    }
    cout<<maxx;
    return 0;
}
