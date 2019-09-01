#include <iostream>
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
ll eular(ll n)
{
    ll ans = n;
    for(ll i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ans -= ans/i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)ans -= ans/n;
    return ans;
}
ll ksm(ll a,ll b,ll mod)
{
    ll ans=1;
    int flag=0;
    int flag2=0;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a;
            if(ans>mod||flag==2)
            {
                flag2=1;
                ans%=mod;
            }
        }
        a=a*a;
        if(a>mod)
        {
            flag=2;
            a%=mod;
        }
        b>>=1;
    }
    if(flag2==1)
        return ans%mod+mod;
    else
        return ans;
}
const ll maxn=1000005;
ll a;
ll ans[20];
ll solve(ll now,ll mod,ll aim)
{
    if(now==aim)
    {
        if(a>mod)
            return a%mod+mod;
        else
            return a;
    }
    ll t=solve(now+1,eular(mod),aim);
    ll tans=ksm(a,t,mod);
    return tans;
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
    ll t;
    cin>>t;
    while(t--)
    {
        ll b,m;
        cin>>a>>b>>m;
        int i;
        wfor(i,1,11)
        {
            ans[i]=solve(1,m,i);
        }
        ll res;
        if(b>=10)
            res=ans[10];
        else
            res=ans[b];
        if(a==1||b==0)
        {
            res=1;
        }
        cout<<res%m<<endl;
    }
    return 0;
}
