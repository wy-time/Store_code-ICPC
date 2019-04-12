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
const int maxn = 2e5 + 5;
const int INF = 1e9;
int dp[maxn][3];
int ma[200];
char res[maxn];
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
    ma['R'] = 0;
    ma['G'] = 1;
    ma['B'] = 2;
    int n;
    cin >> n;
    int i;
    string s;
    cin >> s;
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    dp[1][ma[s[0]]] = 0;
    wfor(i, 2, n + 1)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + 1;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + 1;
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + 1;
        dp[i][ma[s[i - 1]]]--;
    }
    int cnt = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << cnt << endl;
    char last = cnt == dp[n][0] ? 'R' : cnt == dp[n][1] ? 'G' : 'B';
    cnt = 0;
    mfor(i, n - 1, 1)
    {
        res[cnt++] = last;
        if (last == 'R')
            last = dp[i][1] > dp[i][2] ? 'B' : 'G';
        else if (last == 'G')
            last = dp[i][0] > dp[i][2] ? 'B' : 'R';
        else
            last = dp[i][1] > dp[i][0] ? 'R' : 'G';
    }
    res[cnt++] = last;
    mfor(i, cnt - 1, 0)
    {
        cout << res[i];
    }
    return 0;
}
