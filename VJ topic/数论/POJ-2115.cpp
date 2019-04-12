#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return g;
}
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
    ll a, b, c, k;
    while (cin >> a >> b >> c >> k)
    {
        if (a == 0 && b == 0 && c == 0 && k == 0)
            break;
        ll mod = 1ll << k;
        ll X = 0, Y = 0;
        ll g = exgcd(c, mod, X, Y);
        ll C = a - b;
        X *= -1;
        if (C == 0 && c == 0)
        {
            cout << 0 << endl;
            continue;
        }
        mod /= g;
        if (C % g == 0)
        {
            ll ans = X * C / g;
            if (ans < 0)
                ans = ans % mod + mod;
            else
                ans = ans % mod;
            cout << ans % mod << endl;
        } else
            cout << "FOREVER" << endl;
    }
    return 0;
}
