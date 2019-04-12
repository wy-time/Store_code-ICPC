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
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	ll t;
	cin >> t;
	while (t--)
	{
		ll a, n;
		cin >> n >> a;
		if (n > 2 || n == 0)
		{
			cout << -1 << " " << -1 << endl;
		} else if (n == 1)
		{
			cout << 1 << " " << a + 1 << endl;
		} else
		{
			// if (a > 1 && a % 2 != 0)
			// {
			// 	ll temp = (a - 1) / 2;
			// 	ll b = 2 * temp * temp + 2 * temp;
			// 	ll c = b + 1;
			// 	cout << b << " " << c << endl;
			// } else if (a > 4 && a % 2 == 0)
			// {
			// 	ll temp = a / 2;
			// 	ll b = temp * temp - 1;
			// 	ll c = temp * temp + 1;
			// 	cout << b << " " << c << endl;
			// } else
			// {
			// 	cout << -1 << " " << -1 << endl;
			// }
			ll i = 1;
			while (a * a - i * i > 0)
			{
				if ((a * a - i * i) % i == 0)
					break;
				i++;
			}
			if ((a * a - i * i) > 0)
			{
				ll b = (a * a - i * i) / i / 2;
				ll c = sqrt(a * a + b * b);
				cout << b << " " << c << endl;
			} else
				cout << -1 << " " << -1 << endl;
		}
	}
	return 0;
}
