#include <iostream>
#include <iomanip>
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
const double pi = 3.1415927;
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
    double d, sec;
    int r;
    int cnt = 0;
    while (cin >> d >> r >> sec)
    {
        if (r == 0)
            break;
        cnt++;
        double ans1 = pi * d * r / 12 / 5280;
        double tim = sec / 3600;
        double ans2 = ans1 / tim;
        cout << "Trip #" << cnt << ": ";
        cout << fixed << setprecision(2) << ans1 << " " << ans2 << endl;
    }
    return 0;
}
