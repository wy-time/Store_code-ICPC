#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const int maxn = 1e6 + 5;
double num[maxn];
void init()
{
	int cnt = 0;
	int i;
	double ans = 0;
	wfor(i, 1, 100000005)
	{
		ans += 1.0 / i;
		if (i % 100 == 0)
			num[++cnt] = ans;
	}
}
int main()
{
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	// cin >> t;
	read(t);
	init();
	int n;
	int casecnt = 0;
	while (t--)
	{
		casecnt++;
		// cin >> n;
		read(n);
		int rest = n % 100;
		double res = num[n / 100];
		int i;
		wfor(i, n / 100 * 100 + 1, n / 100 * 100 + rest + 1)
		{
			res += 1.0 / i;
		}
		// cout << "Case" << casecnt << ": ";
		printf("Case %d: %.10f\n", casecnt, res);
	}
	return 0;
}
