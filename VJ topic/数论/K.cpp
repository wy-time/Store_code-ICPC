#include <iostream>
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
const ll maxn = 1e12;
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
		int n;
		cin >> n;
		ll l = 1;
		ll r = maxn;
		ll res = 0;
		n--;
		while (l < r)
		{
			ll mid = (l + r) >> 1;
			ll ans = 0;
			ll tmp = mid;
			while (1)
			{
				ans += tmp / 5;
				tmp /= 5;
				if (tmp == 0)
					break;
			}
			if (ans < n)
				l = mid + 1;
			else if (ans > n)
				r = mid - 1;
			else if (ans == n)
				break;
		}
		res = (l + r) >> 1;
		cout << "Case " << casecnt << ": " << res << endl;
	}
	return 0;
}
