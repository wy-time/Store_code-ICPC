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
const ll maxn=3e5+5;
ll p[maxn];
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
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
    ll n,m;
    cin>>n>>m;
    ll i;
    ll g=0;
    ll t;
    cin>>t;
    ll last=t;
    ll beg=t;
    wfor(i,1,n)
    {
        cin>>t;
        g=gcd(t-last,g);
        last=t;
    }
    ll ans=0;
    ll flag=0;
    wfor(i,0,m)
    {
        cin>>p[i];
    }
    wfor(i,0,m)
    {
        if(g%p[i]==0)
        {
            flag=1;
            ans=i+1;
        }
    }
    if(flag==1)
    {
        cout<<"YES"<<endl;
        cout<<beg<<" "<<ans<<endl;
    }else
        cout<<"NO"<<endl;
    return 0;
}
