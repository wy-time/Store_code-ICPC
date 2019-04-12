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
ll cal_eul(ll t)
{
    ll i;
    ll ans = t;
    for (i = 2; i * i <= t; i++)
    {
        if (t % i == 0)
        {
            ans = ans / i * (i - 1);
            while (t % i == 0)
                t /= i;
        }
    }
    if (t > 1)
        ans = ans / t * (t - 1);
    return ans;
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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll i;
        ll ans = 0;
        for (i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i >= m)
                {
                    ans += cal_eul(n / i);
                }
                if (i * i != n && n / i >= m)
                {
                    ans += cal_eul(i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
