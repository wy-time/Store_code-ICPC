#include <iostream>
#include <cmath> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll mod=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    ll l,r;
    cin>>l>>r;
    ll begroup=floor(log2(l))+1;
    ll endgroup=floor(log2(r))+1;
    ll ans=0;
    if(begroup!=endgroup)
    {
        if(begroup%2==0)
        {
            ll even=begroup/2;
            ll beg=2ll*(1ll-ksm(4,even-1))/(1-4)+1;
            ll firstnum=beg*2;
            beg=(1ll-ksm(2,begroup-1))/(1-2)+1;
            firstnum+=(l-beg)*2;
            ll len=ksm(2,begroup-1);
            len-=(l-beg);
            ans=ans+((len%mod)*(firstnum%mod)+((len%mod)*((len%mod)-1ll)%mod));
            ans%=mod;
        }else
        {
            ll odd=(begroup+1)/2;
            ll beg=(1ll-ksm(4,odd-1))/(1-4)+1;
            ll firstnum=beg*2-1;
            beg=(1ll-ksm(2,begroup-1))/(1-2)+1;
            firstnum+=(l-beg)*2ll;
            ll len=ksm(2,begroup-1);
            len-=(l-beg);
            ans=ans+((len%mod)*(firstnum%mod)+((len%mod)*((len%mod)-1ll)%mod));
            ans%=mod;
        }
        if(endgroup%2==0)
        {
            ll even=endgroup/2;
            ll beg=2ll*(1ll-ksm(4,even-1))/(1-4)+1;
            ll firstnum=beg*2;
            beg=(1ll-ksm(2,endgroup-1))/(1-2)+1;
            ll len=ksm(2,endgroup-1);
            len=r-beg+1;
            ans=ans+((len%mod)*(firstnum%mod)+((len%mod)*((len%mod)-1ll)%mod));
            ans%=mod;
        }else
        {
            ll odd=(endgroup+1)/2;
            ll beg=(1ll-ksm(4,odd-1))/(1-4)+1;
            ll firstnum=beg*2-1;
            beg=(1ll-ksm(2,endgroup-1))/(1-2)+1;
            ll len=ksm(2,endgroup-1);
            len=r-beg+1;
            ans=ans+((len%mod)*(firstnum%mod)+((len%mod)*((len%mod)-1ll)%mod));
            ans%=mod;
        }
        ll i;
        wfor(i,begroup+1,endgroup)
        {
            if(i%2==0)
            {
                ll even=i/2;
                ll beg=2ll*(1ll-ksm(4,even-1))/(1-4)+1;
                ll firstnum=beg*2;
                ll len=ksm(2,i-1);
                ans=ans+((len%mod)*(firstnum%mod)+((len%mod)*((len%mod)-1ll)%mod));
                ans%=mod;
            }else
            {
                ll odd=(i+1)/2;
                ll beg=(1ll-ksm(4,odd-1))/(1-4)+1;
                ll firstnum=beg*2-1;
                ll len=ksm(2,i-1);
                ans=ans+((len%mod)*(firstnum%mod)+((len%mod)*((len%mod)-1ll)%mod));
                ans%=mod;
            }
        }
    }else
    {
        if(begroup%2==0)
        {
            ll even=begroup/2;
            ll beg=2ll*(1ll-ksm(4,even-1))/(1-4)+1;
            ll firstnum=beg*2;
            beg=(1ll-ksm(2,begroup-1))/(1-2)+1;
            firstnum+=(l-beg)*2;
            ll len=r-l+1;
            ans=ans+((len%mod)*(firstnum%mod)+((len%mod)*((len%mod)-1ll)%mod));
            ans%=mod;
        }else
        {
            ll odd=(begroup+1)/2;
            ll beg=(1ll-ksm(4,odd-1))/(1-4)+1;
            ll firstnum=beg*2-1;
            beg=(1ll-ksm(2,begroup-1))/(1-2)+1;
            firstnum+=(l-beg)*2ll;
            ll len=r-l+1;
            ans=ans+((len%mod)*(firstnum%mod)+((len%mod)*((len%mod)-1ll)%mod));
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
