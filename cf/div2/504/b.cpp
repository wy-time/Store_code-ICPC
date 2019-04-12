#include <iostream>
#ifdef test
#include <cstdio>
#endif
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
	ll n, m;
	cin >> n >> m;
	if (m >= 2 * n)
	{
		cout << 0 << endl;
		return 0;
	}
	if (m > n)
	{
		ll t = m - n;
		if ((n - t) % 2 != 0)
		{
			cout << (n - t + 1) / 2 << endl;
		} else
			cout << (n - t) / 2 << endl;
	}
	else if (m <= n)
	{
		if (m % 2 == 0)
			cout << m / 2 - 1 << endl;
		else
			cout << m / 2 << endl;
	}
	return 0;
}
