#include <iostream>
#include<algorithm>
using namespace std;
int ans[200005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int i;
    for(i=0; i<n; i++)
    {
        cin>>ans[i];
    }
    if(k>n)
    {
        cout<<-1;
        return 0;
    }
    sort(ans,ans+n);
    if(k==0)
    {
        if(ans[0]>1)
            cout<<ans[0]-1;
        else
            cout<<-1;
    }
    else if(k<n)
    {
        if(ans[k]!=ans[k-1])
        {
            cout<<ans[k-1];
        }
        else
            cout<<-1;
    }else if(k==n)
    {
        if(ans[n-1]<=1000000000)
            cout<<ans[n-1];
        else
            cout<<-1;
    }
    return 0;
}
