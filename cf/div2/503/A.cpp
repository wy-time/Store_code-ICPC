#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	while (k--)
	{
		ll t1, f1, t2, f2;
		cin >> t1 >> f1 >> t2 >> f2;
		ll res = 0;
		if (t1 == t2)
		{
			res = abs(f2 - f1);
		} else
		{
			if (t1 < t2)
			{
				if (f1 < a)
				{
					res += a - f1;
					f1 = a;
				} else if (f1 > b)
				{
					res += f1 - b;
					f1 = b;
				}
				res += t2 - t1;
				res += abs(f2 - f1);
			} else
			{
				if (f1 < a)
				{
					res += a - f1;
					f1 = a;
				} else if (f1 > b)
				{
					res += f1 - b;
					f1 = b;
				}
				res += t1 - t2;
				res += abs(f1 - f2);
			}
		}
		cout << res << endl;
	}
	return 0;
}
