#include <iostream>
#include <iomanip>
#include <cmath>
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
const double eps = 1e-8;
int equa(double a, double b)
{
    if (abs(a - b) < eps)
        return 1;
    else
        return 0;
}
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
    ll n;
    ll k, m;
    cin >> n >> k >> m;
    ll sum = 0;
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i];
        sum += num[i];
    }
    sort(num, num + n);
    ll cnt = 0;
    double ans = (sum + min(n * k, m)) / n;
    while (cnt < m && n > 1)
    {
        double shan = 0;
        if (((n - 1)*k) <= (m - cnt - 1))
        {
            shan = 1.0 * (sum - num[cnt] + (n - 1) * k) / (n - 1);
        } else
            shan = 1.0 * (sum - num[cnt] + m - cnt - 1) / (n - 1);
        sum -= num[cnt];
        cnt++;
        n--;
        ans = max(shan, ans);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
