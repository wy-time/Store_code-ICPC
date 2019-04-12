#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
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
	ll n, p;
	ll i;
	ll ans = 0x7f7f7f7f7f7f7f7f;
	cin >> n >> p;
	ll s = p + 1;
	wfor(i, 2, s)
	{
		ll cnt = 0;
		if (p % i == 0)
		{
			while (p % i == 0)
			{
				cnt++;
				p /= i;
			}
			ll prime = i;
			ll cnt2 = 0;
			ll m = n;
			if (cnt != 0)
			{
				while (1)
				{
					cnt2 += m / prime;
					m = m / prime;
					if (m == 0)
						break;
				}
				ans = min(cnt2 / cnt, ans);
			}
		}
	}
	cout << ans << endl;
	return 0;
}