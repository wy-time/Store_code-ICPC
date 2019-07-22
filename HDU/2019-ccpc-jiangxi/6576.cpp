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
const ll maxn = 1005;
ll num[maxn];
ll ans[maxn];
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
        ll i;
        wfor(i, 0, n)
        {
            cin >> num[i];
        }
        if (n == 1)
        {
            cout << "Yes" << endl;
            cout << m << endl;
        } else
        {
            ll value = num[0] * num[1] / gcd(num[0], num[1]);
            wfor(i, 2, n)
            {
                value = value * num[i] / gcd(value, num[i]);
            }
            ll sum = 0;
            wfor(i, 0, n)
            {
                ans[i] = value / num[i];
                sum += ans[i];
            }
            ll mul = 1;
            if (m % sum == 0)
            {
                mul = m / sum;
                cout << "Yes" << endl;
                wfor(i, 0, n - 1)
                {
                    cout << ans[i]*mul << " ";
                }
                cout << ans[i]*mul << endl;
            } else
                cout << "No" << endl;
        }
    }
    return 0;
}
