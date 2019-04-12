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
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
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
		ll a, b, l;
		cin >> a >> b >> l;
		ll k = a * b / gcd(a, b);
		ll ans = -1;
		cout << "Case " << casecnt << ": ";
		if (l % k != 0)
			cout << "impossible" << endl;
		else
		{
			ll temp = l / k;
			ll i;
			for (i = 1; i * temp <= l; i++)
			{
				ll x = i * temp;
				if (x * k / gcd(x, k) == l)
				{
					ans = x;
					break;
				}
			}
			if (ans != -1)
				cout << ans << endl;
			else
				cout << "impossible" << endl;
		}
	}
	return 0;
}
