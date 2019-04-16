#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(ll &x) {
    char ch = getchar(); x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 5;
ll fac[maxn];
ll inv[maxn];
ll sum[maxn + 1];
ll ksm(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void init()
{
    fac[1] = fac[0] = inv[0] = inv[1] = 1;
    ll i;
    wfor(i, 2, maxn)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[maxn - 1] = ksm(fac[maxn - 1], mod - 2);
    mfor(i, maxn - 2, 2)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    sum[1] = 1;
    wfor(i, 2, maxn)
    {
        sum[i] = sum[i - 1] + i;
    }
}
int main()
{
//     std::ios::sync_with_stdio(false);
// #ifdef test
//     freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
//     freopen("/home/time/debug/debug/in", "r", stdin);
//     freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
    ll t;
    read(t);
    // cin >> t;
    init();
    while (t--)
    {
        ll n;
        // cin >> n;
        read(n);
        if (n == 1)
        {
            // cout << 1 << endl;
            printf("1\n");
            continue;
        }
        ll pos = lower_bound(sum + 1, sum + 1 + maxn, n) - sum;
        ll x = 0;
        ll ans = 0;
        if (sum[pos] == n)
        {
            x = 1;
            ans = fac[pos + x - 1] * inv[x - 1];
            ans /= pos;
            ans *= (pos + 1);
        } else
        {
            x = 1e9;
            ll N = 0;
            ll cha;
            cha = sum[pos] - n;
            ll fixpos = lower_bound(sum + 1, sum + 1 + maxn, cha) - sum;
            if (sum[fixpos] == cha)
            {
                x = fixpos + 1;
                N = pos - x + 1;
                ans = fac[x + N - 1] * inv[x - 1] % mod;
            } else
            {
                cha = n - sum[pos - 1];
                ll fix = cha + 1;
                ll temp = fix / (pos - 2);
                fix %= (pos - 2);
                ans = fac[pos - 1 - fix + temp] * inv[pos - 2 - fix + temp] % mod;
                ans = ans * fac[pos + temp] % mod * inv[pos + temp - fix] % mod;
            }
        }
        // cout << ans % mod << endl;
        printf("%lld\n", ans % mod);
    }
    return 0;
}
