#include <iostream>
#include <iomanip>
#include <cmath>
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
    int t;
    cin >> t;
    int casecnt = 0;
    while (t--)
    {
        casecnt++;
        int n, m;
        cin >> n >> m;
        double ans = 0;
        if (n % 2 != 0 && m % 2 != 0)
        {
            ans += n * m - 1;
            ans += sqrt(2.0);
        } else
            ans = n * m;
        cout << "Scenario #" << casecnt << ":" << endl;
        cout << fixed << setprecision(2) << ans << endl << endl;
    }
    return 0;
}
