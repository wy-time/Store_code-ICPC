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
inline ll ksc(ll x, ll y, ll mod)
{
    return (x * y - (ll)((long double)x / mod * y) * mod + mod) % mod;
}
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
ll ksm(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ksc(ans , a , mod);
        a = ksc(a , a , mod);
        b >>= 1;
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
// #ifdef test
//     freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
//     freopen("/home/time/debug/debug/in", "r", stdin);
//     freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
    ll r, t, m;
    while (cin >> r >> t >> m)
    {
        ll mod = r;
        // ll X = 0, Y = 0;
        // exgcd(1, mod, X, Y);
        ll C = ksm(m, t, mod);
        // mod /= g;
        // X%=mod
        // cout << g << endl;
        ll ans = C;
        // if (X < 0)
        //     ans = ans % mod + mod;
        // else
        //     ans = ans % mod;
        cout << ans % mod << endl;
    }
    return 0;
}
