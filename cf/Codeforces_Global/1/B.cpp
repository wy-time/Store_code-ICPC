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
const int maxn = 1e5 + 5;
int sum[maxn];
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
    cin >> n >> m >> k;
    int i;
    int last;
    cin >> last;
    int ans = last;
    wfor(i, 0, n - 1)
    {
        int t;
        cin >> t;
        sum[i] = t - last;
        last = t;
    }
    ans = last - ans;
    sort(sum, sum + n, greater<int>());
    wfor(i, 0, k - 1)
    {
        ans -= sum[i];
    }
    cout << ans + k << endl;
    return 0;
}
