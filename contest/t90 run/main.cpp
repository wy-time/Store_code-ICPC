#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[1000005];
ll b[1000005];
int main()
{
    std::ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(b,b+n);
    ll ans=0;
    int cnt=0;
    ll temp=0;
    for(i=0;i<n;i++)
    {
        cnt++;
        temp+=b[n-1-i]-a[i];
        if(cnt%3==0)
            temp+=m;
        ans=max(ans,temp);
    }
    cout<<ans;
    return 0;
}
