#include <iostream>
using namespace std;
const int mod=1000000007;
int main()
{
    std::ios::sync_with_stdio(false);
    int q,k;
    cin>>q>>k;
    long long ans[100005]={0};
    ans[1]=1;
    int i;
    for(i=2;i<=k;i++)
    {
        ans[i]=1;
    }
    ans[k+1]=2;
    for(i=k+2;i<100005;i++)
    {
        ans[i]=(ans[i-1]%mod+ans[i-k-1]%mod)%mod;
    }
    long long sum[100005]={0};
    for(i=1;i<100005;i++)
    {
        sum[i]=(ans[i]%mod+sum[i-1]%mod)%mod;
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        long long res=((sum[r+1]-sum[l])+mod)%mod;
        cout<<res<<endl;
    }
    return 0;
}
