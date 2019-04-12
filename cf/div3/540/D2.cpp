#include <iostream>
#include <algorithm>
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
    int i;
    int sum = 0;
    wfor(i, 0, n)
    {
        cin >> num[i];
        sum += num[i];
    }
    int flag = 1;
    if (sum < m)
        flag = 0;
    int ans = 1e8;
    if (flag != 0)
    {
        sort(num, num + n, greater<int>());
        int L, R;
        L = 1, R = n;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            ll now = 0;
            ll sub = 0;
            int j, k;
            for (k = 0; k < n;)
            {
                if (num[k] - sub <= 0)
                {
                    break;
                }
                wfor(j, 1, mid + 1)
                {
                    if (num[k] - sub > 0)
                        now += num[k] - sub;
                    else
                        break;
                    k++;
                }
                sub++;
            }
            if (now >= m)
            {
                ans = min(mid, ans);
                R = mid - 1;
            } else
                L = mid + 1;
        }
        cout << ans << endl;
    } else
        cout << -1 << endl;
    return 0;
}
