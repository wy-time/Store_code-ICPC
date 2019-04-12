#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef unsigned long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
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
		ll n;
		cin >> n;
		ll l = 1, r = 0;
		ll ans = 0;
		for (l = 2; l <= n && r <= n; l = r + 1)
		{
			r = n / (n / l);
			ll times = n / l - 1;
			ll num = r - l + 1;
			ans += (num * l + (num * (num - 1)) / 2) * times;
		}
		cout << "Case " << casecnt << ": " << ans << endl;
	}
	return 0;
}
