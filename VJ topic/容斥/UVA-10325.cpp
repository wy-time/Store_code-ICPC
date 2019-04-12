#include <iostream>
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
ll num[20];
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
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
    ll n, m;
    while (cin >> n >> m)
    {
        ll ans = n;
        ll i;
        wfor(i, 0, m)
        {
            cin >> num[i];
        }
        ll maxnum = 1 << m;
        ll j;
        wfor(i, 1, maxnum)
        {
            ll temp = 1;
            ll g = 0;
            ll cnt = 0;
            ll k = 0;
            ll flag = 1;
            for (j = 1; j <= i; j <<= 1)
            {
                if ((j & i) == j)
                {
                    cnt++;
                    if (cnt != 1)
                    {
                        temp *= num[k];
                        g = temp / gcd(num[k], g);
                        temp = g;
                    } else
                    {
                        temp *= num[k];
                        g = gcd(num[k], g);
                    }
                    if (temp > n * g || temp < 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                k++;
            }
            if (flag)
            {
                temp = n / temp;
                if (cnt % 2 == 0)
                {
                    ans += temp;
                } else
                    ans -= temp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
