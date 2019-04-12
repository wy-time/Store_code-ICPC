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
const int maxn = 2e5 + 5;
ll dp[maxn][3];
const int mod = 1e9 + 7;
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
    int n, l, r;
    cin >> n >> l >> r;
    int fix[3] = {l % 3 == 0 ? l : l + 3 - l % 3, l % 3 == 1 ? l : l % 3 == 0 ? l + 1 : l + 2, l % 3 == 2 ? l : l % 3 == 0 ? l + 2 : l + 1};
    int i;
    wfor(i, 0, 3)
    {
        if (r - fix[i] >= 0)
            dp[1][i] = (r - fix[i] + 1) % 3 == 0 ? (r - fix[i] + 1) / 3 : (r - fix[i] + 1) / 3 + 1;
    }
    wfor(i, 2, n + 1)
    {
        dp[i][0] = dp[i - 1][0] * dp[1][0] % mod + dp[i - 1][1] * dp[1][2] % mod + dp[i - 1][2] * dp[1][1] % mod;
        dp[i][0] %= mod;
        dp[i][1] = dp[i - 1][0] * dp[1][1] % mod + dp[i - 1][1] * dp[1][0] % mod + dp[i - 1][2] * dp[1][2] % mod;
        dp[i][1] %= mod;
        dp[i][2] = dp[i - 1][0] * dp[1][2] % mod + dp[i - 1][1] * dp[1][1] % mod + dp[i - 1][2] * dp[1][0] % mod;
        dp[i][2] %= mod;
    }
    cout << dp[n][0] << endl;
    return 0;
}
