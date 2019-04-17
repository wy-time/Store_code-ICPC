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
const double PI = acos(-1.0);
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
    int n, d;
    while (cin >> n >> d)
    {
        int i;
        double ans = 0;
        wfor(i, 0, n)
        {
            int t;
            cin >> t;
            ans += 1.0 * d * d * sin(1.0 * t / 180.0 * PI) / 2;
        }
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}
