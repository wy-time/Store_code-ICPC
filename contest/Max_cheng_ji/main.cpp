#include <iostream>
using namespace std;
unsigned long long ksm(unsigned long long a,unsigned long long b,unsigned long long mod);
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    const unsigned long long mod=2000000000000000003L;
    while(t--)
    {
        unsigned long long sum;
        cin>>sum;
        unsigned long long res=0;
        unsigned long long temp=sum/3;
        if(sum==1)
        {
            cout<<1<<endl;;
        }else if(sum==2)
        {
            cout<<2<<endl;
        }else if(sum==0)
        {
            cout<<0<<endl;
        }
        else
        {
            if(sum%3==1)
            {
                res=ksm((unsigned long long)3,(unsigned long long)temp-1,mod);
                res%=mod;
                res*=4;
                res%=mod;
            }else
            {
                res=ksm((unsigned long long)3,(unsigned long long)temp,mod);
                res%=mod;
                if(sum%3!=0)
                    res*=sum%3;
                res%=mod;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
unsigned long long ksm(unsigned long long a,unsigned long long b,unsigned long long mod)
{
    unsigned long long res=1;
    unsigned long long t=a;
    while(b)
    {
        if(b&1)
        {
            res=(res%mod*t%mod)%mod;
        }
        t=(t%mod*t%mod)%mod;
        b>>=1;
    }
    return res%mod;
}
