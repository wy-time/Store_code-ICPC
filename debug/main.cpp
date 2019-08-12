#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(ll &x) {
char ch = getchar(); x = 0;
for (; ch < '0' || ch > '9'; ch = getchar());
for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const ll mod=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
const ll maxn=500005;
ll sum[maxn];
ll ans[maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    ll t;
    //cin>>t;
    read(t);
    while(t--)
    {
        ll n,m;
        //cin>>n>>m;
        read(n);
        read(m);
        ll i;
        sum[1]=0;
        ans[1]=0;
        wfor(i,0,n)
        {
            ll s,r,x,a;
            read(r);
            read(s);
            read(x);
            read(a);
            a%=mod;
            //cin>>r>>s>>x>>a;
            ll temp=(s%mod*ksm(r,mod-2))%mod;
            sum[i+2]=(((temp-1+mod)%mod)*((ans[i+1]-ans[x]+mod)%mod)%mod+temp*a%mod)%mod;
            ans[i+2]=(sum[i+2]+ans[i+1])%mod;
        }
        wfor(i,0,m)
        {
            ll l,r;
            //cin>>l>>r;
            read(l);read(r);
            printf("%lld\n",(ans[r]-ans[l]+mod+mod)%mod);
            //cout<<(ans[r]-ans[l]+mod)%mod<<endl;
        }
    }
    return 0;
}
