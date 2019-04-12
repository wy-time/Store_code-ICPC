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
const int maxn = 5005;
int dp[maxn][maxn][2];
int num[maxn];
const int INF = 1e8;
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
    wfor(i, 1, n + 1)
    {
        cin >> num[i];
    }
    int j;
    wfor(i, 1, n + 1)
    {
        wfor(j, 1, n + 1)
        {
            dp[i][j][1] = dp[i][j][0] = i == j ? 0 : INF;
        }
    }
    wfor(j, 1, n + 1)
    {
        mfor(i, j, 1)
        {
            int k;
            wfor(k, 0, 2)
            {
                int tag = k == 0 ? num[i] : num[j];
                if (i - 1 >= 1)
                    dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][k] + (int)(tag != num[i - 1]));
                if (j + 1 <= n)
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + (int)(tag != num[j + 1]));
            }
        }
    }
    int ans = 1e8;
    ans = min(dp[1][n][0], dp[1][n][1]);
    cout << ans << endl;
    return 0;
}
