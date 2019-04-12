#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	ll n, q;
	cin >> n >> q;
	ll i;
	wfor(i, 0, q)
	{
		long long x, y;
		cin >> x >> y;
		long long res = 0;
		if ((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0))
		{
			if (n % 2 == 0)
			{
				res = (n / 2) * (x - 1) + ((y % 2 == 0 ? y : y + 1) / 2);
			}
			else
			{
				if (x % 2 == 0)
					res = (x - 1) / 2 * n + (n + 1) / 2 + y / 2;
				else
					res = x / 2 * n + (y + 1) / 2;
			}
		} else
		{
			if (n % 2 == 0)
				res = n / 2 * n + (x - 1) * (n / 2) + ((y % 2 == 0 ? y : y + 1) / 2);
			else
			{
				if (x % 2 == 0)
					res = n / 2 * n + (n + 1) / 2 + (x - 1) / 2 * n + n / 2 + (y + 1) / 2;
				else
					res = n / 2 * n + (n + 1) / 2 + x / 2 * n + y / 2;
			}
		}
		cout << res << endl;
	}
	return 0;
}
