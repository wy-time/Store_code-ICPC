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
    int n, r;
    cin >> n >> r;
    double t = 1 - cos(2.0 * PI / n);
    double a = 4.0 - 2.0 * t;
    double b = -4.0 * t * r;
    double c = -2.0 * t * r * r;
    double ans = max((-b + sqrt(b * b - 4.0 * a * c)) / a / 2.0, (-b - sqrt(b * b - 4.0 * a * c)) / a / 2.0);
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}
