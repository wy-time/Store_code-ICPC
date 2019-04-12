#include <iostream>
#include <cmath>
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
    ll x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    ll X = 0, Y = 0;
    if (n < m)
    {
        swap(n, m);
        swap(x, y);
    }
    ll g = exgcd(n - m, L, X, Y);
    ll c = x - y;
    if (c % g != 0)
        cout << "Impossible" << endl;
    else
    {
        ll ans = X * c / g;
        if (ans < 0)
            ans = ans % L + L;
        else
            ans = ans % L;
        cout << ans << endl;
    }
    return 0;
}
