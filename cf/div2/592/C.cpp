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
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll g = exgcd(b, a % b, x, y);
	ll t = x;
	x = y;
	y = t - a / b * y;
	return g;
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	ll n, p, w, d;
	cin >> n >> p >> w >> d;
	ll x, y;
	ll g = exgcd(w, d, x, y);
	if (p % g != 0)
		cout << -1 << endl;
	else
	{
		x = x * p / g;
		y = y * p / g;
		ll kx = d / g;
		ll ky = w / g;
		int flag = 1;
		if (x < 0)
		{
			ll temp = -x;
			temp = temp / kx + (temp % kx != 0);
			x += temp * kx;
			y -= temp * ky;
			if (y < 0)
				flag = 0;
		}
		if (flag && y < 0)
		{
			ll temp = -y;
			temp = temp / ky + (temp % ky != 0);
			y += temp * ky;
			x -= temp * kx;
			if (x < 0)
				flag = 0;
		}
		if (flag)
		{
			if (x + y <= n)
				cout << x << " " << y << " " << n - x - y << endl;
			else
			{
				if (kx > ky)
				{
					ll cnt = x / kx;
					x -= cnt * kx;
					y += cnt * ky;
				} else
				{
					ll cnt = y / ky;
					y -= cnt * ky;
					x += cnt * kx;
				}
				if (x < 0)
				{
					ll temp = -x;
					temp = temp / kx + (temp % kx != 0);
					x += temp * kx;
					y -= temp * ky;
					if (y < 0)
						flag = 0;
				}
				if (flag && y < 0)
				{
					ll temp = -y;
					temp = temp / ky + (temp % ky != 0);
					y += temp * ky;
					x -= temp * kx;
					if (x < 0)
						flag = 0;
				}
				if (flag)
				{
					if (x + y <= n)
						cout << x << " " << y << " " << n - x - y << endl;
					else
						cout << -1 << endl;
				} else
					cout << -1 << endl;
			}
		} else
			cout << -1 << endl;
	}
	return 0;
}
