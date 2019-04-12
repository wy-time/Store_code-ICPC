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
		ll l = 1, r = 1;
		ll res = 0;
		for (l = 1; l <= n && r <= n; l = r + 1)
		{
			r = n / (n / l);
			res += (n / l) * (r - l + 1);
			l = r + 1;
		}
		cout << "Case " << casecnt << ": " << res << endl;
	}
	return 0;
}
