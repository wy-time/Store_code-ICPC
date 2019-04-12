#include <iostream>
using namespace std;
long long ans[2005];
long long r[2005];
const long long mod =1000000007;
int main()
{
    std::ios::sync_with_stdio(false);
    long long n,k;
    cin>>n>>k;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>ans[i];
    }
    r[0]=ans[0]%mod;
    int j;
    for(i=1;i<n;i++)
    {
        long long temp=0;
        for(j=1;j<=i;j++)
        {
            temp+=((ans[i-j]%mod)*((k+(i-j))%mod))%mod;
            temp%=mod;
        }
        temp+=ans[i]%mod;
        r[i]=temp%mod;
    }
    for(i=0;i<n-1;i++)
        cout<<r[i]<<" ";
    cout<<r[i];
    return 0;
}
