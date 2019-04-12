#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct po
{
	int x;
	int y;
};
po point[105];
double cal(po a, po b)
{
	return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double ans[3000000];
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
	while (t--)
	{
		int n, ak;
		cin >> n >> ak;
		int i;
		wfor(i, 0, n)
		{
			cin >> point[i].x >> point[i].y;
		}
		int j;
		int k;
		int cnt = 0;
		wfor(i, 0, n)
		{
			wfor(j, i, n)
			{
				wfor(k, j, n)
				{
					double a, b, c;
					if (point[i].x == point[j].x && point[i].x == point[k].x)
						continue;
					if (point[i].y == point[j].y && point[i].y == point[k].y)
						continue;
					a = cal(point[i], point[j]);
					b = cal(point[i], point[k]);
					c = cal(point[j], point[k]);
					double p = (a + b + c) / 2.0;
					ans[cnt++] = sqrt(p * (p - a) * (p - b) * (p - c));
				}
			}
		}
		sort(ans, ans + cnt, greater<double>());
		cout << fixed << setprecision(2) << ans[ak - 1] << endl;
	}
	return 0;
}
