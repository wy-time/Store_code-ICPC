#include <iostream>
#include <cstring>
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
const int maxn = 5e5 + 5;
pair<int, int>num[maxn];
int len[maxn];
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
    int casecnt = 0;
    while (cin >> n)
    {
        casecnt++;
        int i;
        wfor(i, 0, n)
        {
            cin >> num[i].first >> num[i].second;
        }
        sort(num, num + n);
        int ans = 1;
        len[1] = num[0].second;
        wfor(i, 1, n)
        {
            if (num[i].second > len[ans])
            {
                ans++;
                len[ans] = num[i].second;
            } else
            {
                int pos = lower_bound(len, len + ans, num[i].second) - len;
                len[pos] = num[i].second;
            }
        }
        cout << "Case " << casecnt << ":" << endl << "My king, at most ";
        if (ans > 1)
        {
            cout << ans << " roads can be built." << endl;
        } else
        {
            cout << ans << " road can be built." << endl;
        }
        cout << endl;
    }
    return 0;
}
