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
    ll a,b;
    cin>>a>>b;
    ll now=a*b/gcd(a,b);
    ll k=0;
    ll ans=0;
    while(a+k<=now&&b+k<=now&&k<10000000)
    {
        ll t=(a+k)*(b+k)/gcd(a+k,b+k);
        if(t<now)
        {
            now=t;
            ans=k;
        }
        k++;
    }
    cout<<ans<<endl;
    return 0;
}
