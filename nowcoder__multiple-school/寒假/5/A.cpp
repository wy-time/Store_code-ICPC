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
const double eps = 1e-7;
int equa(double a, double b)
{
	if (fabs(a - b) < eps)
		return 1;
	else return 0;
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
	int l, l2;
	cin >> l >> l2;
	double maxx = sqrt(1.0 * l * l + l2 * l2 + 2 * l * l2);
	// cout << maxx << endl;
	double minx = sqrt(1.0 * l * l + l2 * l2 - 2 * l * l2);
	int t;
	cin >> t;
	while (t--)
	{
		double x, y;
		cin >> x >> y;
		double aim = sqrt(x * x + y * y);
		double ans = 0;
		if ((aim > minx && aim < maxx) || equa(aim, minx) || equa(aim, maxx))
		{
			cout << fixed << setprecision(8) << ans << endl;
		} else
		{
			cout << fixed << setprecision(8) << min(fabs(aim - minx), fabs(aim - maxx)) << endl;
		}
	}
	return 0;
}
