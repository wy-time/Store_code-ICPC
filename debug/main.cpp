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
ll check(ll now,ll n,ll k,ll m)
{
    ll no=(n-k+1);
    ll sorce=m/no;
    ll temp=m-sorce*no;
    temp=n-temp;
    if(temp*(sorce+1)<=now)
        return 1;
    else
        return 0;
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
        ll n,m,k;
        cin>>n>>m>>k;
        if(m==0)
        {
            cout<<k<<endl;
            continue;
        }
        ll l=0,r=(m+1)*n;
        while(l<=r)
        {
            ll mid=(l+r)>>1;
            if(check(mid,n,k,m))
            {
                r=mid-1;
            }else
                l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}
