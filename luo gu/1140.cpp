#include <iostream>
#include <string>
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
int dp[maxn][maxn];
int val[5][5] =
{
    {5, -1, -2, -1, -3},
    { -1, 5, -3, -2, -4},
    { -2, -3, 5, -2, -2},
    { -1, -2, -2, 5, -1},
    { -3, -4, -2, -1, 0}
};
int ma[300];
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
    int len1, len2;
    string s1, s2;
    cin >> len1 >> s1;
    cin >> len2 >> s2;
    ma['A'] = 0;
    ma['C'] = 1;
    ma['G'] = 2;
    ma['T'] = 3;
    ma['-'] = 4;
    int i, j;
    wfor(i, 1, len1 + 1)
    dp[i][0] = dp[i - 1][0] + val[ma[s1[i - 1]]][4];
    wfor(j, 1, len2 + 1)
    dp[0][j] = dp[0][j - 1] + val[ma[s2[j - 1]]][4];
    wfor(i, 1, len1 + 1)
    {
        wfor(j, 1, len2 + 1)
        {
            dp[i][j] = max(dp[i - 1][j - 1] + val[ma[s1[i - 1]]][ma[s2[j - 1]]], max(dp[i][j - 1] + val[ma[s2[j - 1]]][ma['-']], dp[i - 1][j] + val[ma[s1[i - 1]]][ma['-']]));
        }
    }
    cout << dp[len1][len2] << endl;
    return 0;
}
