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
ll d[2*maxn];
ll sumday[2*maxn];
ll sumhug[2*maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    ll n,x;
    cin>>n>>x;
    ll i;
    wfor(i,0,n)
    {
        cin>>d[i];
        d[n+i]=d[i];
    }
    n*=2;
    sumday[1]=d[0];
    sumhug[1]=(d[0]*(d[0]+1)/2);
    wfor(i,2,n+1)
    {
        sumday[i]=sumday[i-1]+d[i-1];
        sumhug[i]=sumhug[i-1]+(d[i-1]*(d[i-1]+1)/2);
    }
    ll ans=0;
    wfor(i,0,n)
    {
        if(sumday[i]>=x)
        {
            ll pos=lower_bound(sumday+1,sumday+n+1,sumday[i]-x)-sumday;
            ll days=sumday[i]-sumday[pos-1];
            ll more=days-x;
            ll cnt=sumhug[i]-sumhug[pos-1];
            cnt-=(more*(more+1)/2);
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}
