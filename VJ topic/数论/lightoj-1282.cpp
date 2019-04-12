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
ll ksm(ll a, ll b, ll mod)
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
int main()
{
    //std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    int casecnt = 0;
    while (t--)
    {
        casecnt++;
        int n, k;
        scanf("%d %d", &n, &k);
        int anslast = ksm(n, k, 1000);
        int len = k * log10(n * 1.0);
        double x = pow(10, k * log10(n * 1.0) - len + 1);
        while (x < 100)
            x *= 10;
        int ans = floor(x);
        printf("Case %d: %03d %03d\n", casecnt, ans, anslast);
    }
    return 0;
}
