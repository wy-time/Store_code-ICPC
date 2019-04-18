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
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
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
    ll a, b;
    while (cin >> a >> b)
    {
        int flag = 0;
        ll x, y;
        ll g = gcd(a, b);
        b *= g;
        if (a * a - 4ll * b >= 0)
        {
            ll dealt = floor(sqrt(1.0 * a * a - 4 * b + 0.5));
            if (dealt * dealt == (a * a - 4 * b))
            {
                if ((a - dealt) % 2 != 0 || (a + dealt) % 2 != 0)
                {
                    continue;
                }
                x = (a - dealt) / (2);
                y = (a + dealt) / 2;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            cout << min(x, y) << " " << max(x, y) << endl;
        } else
            cout << "No Solution" << endl;
    }
    return 0;
}
