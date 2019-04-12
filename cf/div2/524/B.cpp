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
	int q;
	cin >> q;
	while (q--)
	{
		ll l, r;
		cin >> l >> r;
		ll ans = 0;
		if (l % 2 == 0)
		{
			ans -= (r - l + 1) / 2;
			if ((r - l + 1) % 2 != 0)
				ans += r;
		} else
		{
			ans -= (r - l) / 2;
			ans -= l;
			if ((r - l) % 2 != 0)
				ans += r;
		}
		cout << ans << endl;
	}
	return 0;
}
