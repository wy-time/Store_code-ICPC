#include <iostream>
#include <algorithm> 
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
const ll maxn=2e5+5;
ll num[maxn];
ll num2[maxn];
const ll ha=998244353;
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
    ll n;
    cin>>n;
    ll i;
    wfor(i,0,n)
    {
        cin>>num[i];
        num[i]=num[i]*(i+1)*(n-i);
    }
    sort(num,num+n);
    wfor(i,0,n)
    {
        cin>>num2[i];
    }
    sort(num2,num2+n,greater<ll>());
    ll ans=0;
    wfor(i,0,n)
    {
        ans+=num[i]%ha*num2[n-i-1]%ha;
        ans%=ha;
    }
    cout<<ans%ha<<endl;
    return 0;
}
