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
    ll n, k;
    cin >> n >> k;
    int i;
    wfor(i, 0, k)
    {
        cin >> num[i];
    }
    ll maxnum = 1ll << k;
    ll ans = n;
    wfor(i, 1, maxnum)
    {
        int j;
        int k = 0;
        ll temp = 1;
        int cnt = 0;
        int flag = 1;
        ll g = 0;
        for (j = 1; j <= i; j <<= 1)
        {
            if ((i & j) == j)
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
    return 0;
}
