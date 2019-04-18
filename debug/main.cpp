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
    ll a,b,c;
    ll change[7][3]=
    {
        {-1,0,0},
        {0,-1,0},
        {0,0,-1},
        {-1,0,0},
        {0,0,-1},
        {0,-1,0},
        {-1,0,0}
    };
    cin>>a>>b>>c;
    ll i;
    ll ans=0;
    wfor(i,0,7)
    {
        ll tans=0;
        ll j;
        ll a1=a;
        ll b1=b;
        ll c1=c;
        wfor(j,i,7)
        {
            a1+=change[j][0];
            b1+=change[j][1];
            c1+=change[j][2];
            if(a1<0||b1<0||c1<0)
                break;
            tans++;
        }
        if(a1<0||b1<0||c1<0)
        {
            ans=max(tans,ans);
            continue;
        }
        ll week=min(a1/3,min(b1/2,c1/2));
        tans+=week*7;
        a1-=3*week;
        b1-=2*week;
        c1-=2*week;
        wfor(j,0,7)
        {
            a1+=change[j][0];
            b1+=change[j][1];
            c1+=change[j][2];
            if(a1<0||b1<0||c1<0)
                break;
            tans++;
        }
        ans=max(tans,ans);
    }
    cout<<ans<<endl;
    return 0;
}
