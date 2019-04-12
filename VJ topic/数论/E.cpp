#include <iostream>
#include <cstdio>
#include <cmath>
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
const double E = exp(1.0);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	int casecnt = 0;
	while (t--)
	{
		casecnt++;
		int n, base;
		cin >> n >> base;
		cout << "Case " << casecnt << ": ";
		if (n != 0)
		{
			ll res = log(2 * PI * n) / log(base) / 2 + n * (log(n / E) / log(base));
			res += 1;
			cout << res << endl;
		} else
			cout << 1 << endl;
	}
	return 0;
}
