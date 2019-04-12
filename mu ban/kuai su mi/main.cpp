#include <iostream>
using namespace std;
int ksm(long long a,long long b,int mod);
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        int mod;
        cin>>mod;
        int tt;
        cin>>tt;
        while(tt--)
        {
            long long a,b;
            cin>>a>>b;
            ans=(ans+ksm(a,b,mod))%mod;
        }
        cout<<ans<<endl;

    }
    return 0;
}
int ksm(long long a,long long b,int mod)
{
    int ans=1;
    int temp=a%mod;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*temp)%mod;
        }
        temp=(temp*temp)%mod;
        b>>=1;
    }
    return ans;
}
