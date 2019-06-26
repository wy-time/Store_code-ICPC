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
const int maxn = 1e5 + 5;
int num[2][maxn];
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
    memset(num[0], -1, sizeof(num[0]));
    int i;
    wfor(i, 0, k)
    {
        int t;
        cin >> t;
        t--;
        if (num[0][t] == -1)
            num[0][t] = i;
        num[1][t] = i;
    }
    int ans = 0;
    wfor(i, 0, n)
    {
        if (i - 1 >= 0)
        {
            if (num[0][i] == -1)
            {
                ans++;
            }
            else
            {
                int now = num[0][i];
                if (num[0][i - 1] == -1 || num[1][i - 1] < now)
                {
                    ans++;
                }
            }
        }
        if (i + 1 < n)
        {
            if (num[0][i] == -1)
            {
                ans++;
            }
            else
            {
                int now = num[0][i];
                if (num[0][i + 1] == -1 || num[1][i + 1] < now)
                {
                    ans++;
                }
            }
        }
        if (num[0][i] == -1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
