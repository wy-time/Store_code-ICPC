#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
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
	int t;
	cin >> t;
	int casecnt = 0;
	while (t--)
	{
		casecnt++;
		int m, d;
		cin >> m >> d;
		double v = 1.0 * m / d;
		double r = pow(1.0 * v * 3 / 4 / PI, 1.0 / 3);
		cout << fixed << setprecision(4) << "Case " << casecnt << ": " << PI*r*r * 4.0 << endl;
	}
	return 0;
}