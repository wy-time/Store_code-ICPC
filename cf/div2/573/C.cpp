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
const ll maxn=1e5+5;
ll num[maxn];
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
    ll n,m,k;
    cin>>n>>m>>k;
    ll i;
    ll cnt=0;
    wfor(i,0,m)
    {
        cin>>num[i];
    }
    sort(num,num+m);
    ll fix=0;
    ll last=num[0]/k+(num[0]%k!=0);
    ll ans=1;
    wfor(i,0,m)
    {
        ll nowpage=(num[i]-fix)/k+((num[i]-fix)%k!=0);
        if(nowpage==last)
        {
            cnt++;
        }else
        {
            ans++;
            fix+=cnt;
            last=(num[i]-fix)/k+((num[i]-fix)%k!=0);
            cnt=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
