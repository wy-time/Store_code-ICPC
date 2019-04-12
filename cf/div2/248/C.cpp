#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    ll begx, begy;
    ll endx, endy;
    cin >> begx >> begy >> endx >> endy;
    ll n;
    cin >> n;
    ll i;
    ll ans = 0;
    wfor(i, 0, n)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll temp = a * begx + b * begy + c;
        ll temp2 = a * endx + b * endy + c;
        if ((temp > 0 && temp2 < 0) || (temp < 0 && temp2 > 0))
            ans++;
    }
    cout << ans << endl;
    return 0;
}
