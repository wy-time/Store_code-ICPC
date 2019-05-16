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
const ll maxn = 3e5 + 5;
ll dp[maxn][3];
ll num[maxn];
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
    ll n, x;
    cin >> n >> x;
    ll i;
    wfor(i, 1, n + 1)
    {
        cin >> num[i];
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    ll ans = 0;
    wfor(i, 1, n + 1)
    {
        dp[i][0] = max(0ll, dp[i - 1][0] + num[i]);
        dp[i][1] = max(0ll, max(dp[i - 1][0], dp[i - 1][1]) + num[i] * x);
        dp[i][2] = max(0ll, max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + num[i]);
        ans = max(dp[i][2], max(dp[i][1], max(dp[i][0], ans)));
    }
    cout << ans << endl;
    return 0;
}