#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    long long b,p,k;
    cin>>b>>p>>k;
    int t=p;
    long long r=1;
    long long ans=b;
    while(p)
    {
        if(p&1)
        {
            r=r*ans%k;
        }
        p>>=1;
        ans=ans*ans%k;
    }
    cout<<b<<"^"<<t<<" "<<"mod"<<" "<<k<<"="<<r;
    return 0;
}
