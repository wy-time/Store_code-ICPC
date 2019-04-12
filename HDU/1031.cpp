#include <iostream>
#include <algorithm>
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
pair<double, int>num[maxn];
int ans[maxn];
bool cmp(pair<double, int>x, pair<double, int>y)
{
    if (x.first == y.second)
        return x.second < y.second;
    else
        return x.first > y.first;
}
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
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        memset(num, 0, sizeof(num));
        int i;
        wfor(i, 0, n)
        {
            int j;
            wfor(j, 0, m)
            {
                double t;
                cin >> t;
                num[j].first += t;
                num[j].second = j;
            }
        }
        sort(num, num + m, cmp);
        wfor(i, 0, k)
        {
            ans[i] = num[i].second + 1;
        }
        sort(ans, ans + k, greater<int>());
        wfor(i, 0, k - 1)
        cout << ans[i] << " ";
        cout << ans[i] << endl;
    }
    return 0;
}
