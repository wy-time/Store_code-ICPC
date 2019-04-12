#include <iostream>
#include <cstring>
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
const int maxn = 1e6 + 5;
int dp[maxn][3][3];
int num[maxn];
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
    int n, m;
    cin >> n >> m;
    int i, j, k, l;
    wfor(i, 0, n)
    {
        int t;
        cin >> t;
        num[t]++;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    wfor(i, 1, m + 1)
    {
        wfor(j, 0, 3)
        {
            wfor(k, 0, 3)
            {
                wfor(l, 0, 3)
                {
                    int tmp = (num[i] - j - k - l);
                    if (tmp >= 0 && dp[i - 1][k][l] >= 0)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l] + l + tmp / 3);
                    }
                }
            }
        }
    }
    int ans = 0;
    wfor(i, 0, 3)
    {
        wfor(j, 0, 3)
        {
            ans = max(dp[m][i][j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}
