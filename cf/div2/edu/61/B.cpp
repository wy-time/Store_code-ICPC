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
const int maxn = 3e5 + 5;
int num[maxn];
ll sum[maxn];
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
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    sort(num, num + n, greater<int>());
    sum[0] = num[0];
    wfor(i, 1, n)
    {
        sum[i] = sum[i - 1] + num[i];
    }
    int m;
    cin >> m;
    wfor(i, 0, m)
    {
        int t;
        cin >> t;
        ll ans = 0;
        ans += sum[n - 1] - sum[t - 1];
        ans += sum[t - 2];
        cout << ans << endl;
    }
    return 0;
}
