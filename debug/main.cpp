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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, a, b, c;
        cin >> n >> m >> k >> a >> b >> c;
        int pin1 = a * 2;
        int pin2 = b;
        int pin3 = c * 2;
        ll ans = 0;
        if (pin1 <= pin3 && pin1 <= pin2)
        {
            int na = n + k;
            int nv = m + k;
            ans += na / 2 * a;
            ans += nv / 2 * a;
            if (na % 2 != 0 && nv % 2 != 0)
            {
                if (k >= 1)
                    ans += min(c, 2 * a);
                else
                    ans += 2 * a;
            } else
            {
                ans += na % 2 * a;
                ans += nv % 2 * a;
            }
        } else if (pin2 <= pin1 && pin2 <= pin3)
        {
            int na = n + k;
            int nv = m + k;
            ans += na / 3 * b;
            ans += nv / 3 * b;
            if (na % 3 != 0 && nv % 3 != 0)
            {
                int t1 = na % 3;
                int t2 = nv % 3;
                if (t1 == t2 && t1 == 2)
                {
                    if (k >= 2)
                        ans += min(a * 2, min(c * 2, b * 2));
                    else if (k >= 1)
                    {
                        ans += min(a, b) * 2;
                        ans += min(2 * a, min(2 * b, c));
                    }
                } else if (t1 == t2)
                {
                    if (k >= 1)
                    {
                        ans += min(a * 2, min(b * 2, c));
                    } else
                        ans += min(a * 2, b * 2);
                }
            } else
            {
                if (na % 3 != 0)
                    ans += min(a, b);
                if (nv % 3 != 0)
                    ans += min(a, b);
            }
        } else if (pin3 <= pin1 && pin3 <= pin2)
        {
            ans += k * c;
            if (pin1 <= pin2)
            {
                ans += n / 2 * a;
                ans += n % 2 * a;
                ans += m / 2 * a;
                ans += m % 2 * a;
            } else
            {
                ans += n / 3 * b;
                ans += m / 3 * b;
                ans += n % 3 == 0 ? 0 : min(a, b);
                ans += m % 3 == 0 ? 0 : min(a, b);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
