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
const int maxn = 105;
int num[maxn * 2];
int dp[maxn * 2][maxn * 2];
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
    int n;
    cin >> n;
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i];
        num[i + n] = num[i];
    }
    int j, k;
    int ans = 0;
    wfor(j, 1, 2 * n)
    {
        for (i = j - 1; i >= 0 && j - i < n; i--)
        {
            for (k = i; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + num[i] * num[k + 1] * num[j + 1]);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
