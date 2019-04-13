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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k, a, b, c;
        cin >> n >> m >> k >> a >> b >> c;
        ll i, j;
        ll ans = 1e17;
        wfor(i, 0, k + 1)
        {
            ll na = n + k - i;
            ll nv = m + k - i;
            ll te1 = 1e17;
            ll te2 = 1e17;
            ll j1 = na;
            ll j2 = nv;
            wfor(j, 0, j1 + 1)
            {
                na = n + k - i;
                ll temp = 0;
                temp += j * a;
                na -= 2 * j;
                na = max(0ll, na);
                temp += na / 3 * b;
                temp += na % 3 == 0 ? 0 : b;
                te1 = min(temp, te1);
            }
            wfor(j, 0, j2 + 1)
            {
                nv = m + k - i;
                ll temp = 0;
                temp += j * a;
                nv -= 2 * j;
                nv = max(0ll, nv);
                temp += nv / 3 * b;
                temp += nv % 3 == 0 ? 0 : b;
                te2 = min(temp, te2);
            }
            ans = min(ans, te1 + te2 + i * c);
            // ll need1 = na / 2 + na % 2;
            // ll need2 = nv / 2 + nv % 2;
            // ll need = max(need1, need2);
            // wfor(j, 0, need + 2)
            // {
            //     ll temp = i * c;
            //     na = n + k - i;
            //     nv = m + k - i;
            //     if (na >= 2 * j)
            //     {
            //         temp += j * a;
            //         na -= 2 * j;
            //         temp += na / 3 * b;
            //         temp += na % 3 == 0 ? 0 : b;
            //     } else
            //     {
            //         temp += na / 2 * a;
            //         temp += na % 2 * a;
            //     }
            //     if (nv >= 2 * j)
            //     {
            //         temp += j * a;
            //         nv -= j * 2;
            //         temp += nv / 3 * b;
            //         temp += nv % 3 == 0 ? 0 : b;
            //     } else
            //     {
            //         temp += nv / 2 * a;
            //         temp += nv % 2 * a;
            //     }
            //     ans = min(ans, temp);
            // }
        }
        cout << ans << endl;
    }
    return 0;
}
