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
const int maxn = 100005;
int num[maxn];
int value[maxn];
int dp[maxn];
int cnt[maxn];
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
    int n, k;
    cin >> n >> k;
    int i;
    wfor(i, 0, n)
    {
        int t;
        cin >> t;
        value[t]++;
    }
    int ans = 0;
    if (k == 0)
    {
        wfor(i, 0, maxn)
        {
            if (value[i] != 0)
                ans++;
        }
    } else
    {
        int p;
        wfor(p, 0, k)
        {
            int cnt1 = 0;
            for (i = p; i < maxn; i += k)
            {
                cnt[cnt1++] = value[i];
            }
            int j;
            dp[0] = cnt[0];
            dp[1] = cnt[1];
            wfor(j, 2, cnt1)
            {
                dp[j] = max(dp[j - 2] + cnt[j], dp[j - 1]);
            }
            ans += dp[cnt1 - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
