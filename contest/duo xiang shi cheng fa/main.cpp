#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a[505]={0};
    int b[505]={0};
    int i=0,j=0;
    for(i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    int t1=i;
    for(j=0;j<=m;j++)
    {
        cin>>b[j];
    }
    int t2=j;
    int ans[1005]={0};
    for(i=t1-1;i>=0;i--)
    {
        for(j=t2-1;j>=0;j--)
        {
            ans[i+j]+=a[i]*b[j];
        }
    }
    for(i=0;i<n+m;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[i];
    return 0;
}
