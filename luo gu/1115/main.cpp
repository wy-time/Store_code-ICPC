#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[200005];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long ans=-9999999,t=0;
    for(i=0;i<n;i++)
    {
        if(t>0)
            t+=a[i];
        else
            t=a[i];
        if(t>ans)
            ans=t;
    }
    cout<<ans;
    return 0;
}
