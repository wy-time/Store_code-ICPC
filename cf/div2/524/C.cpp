#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct PO
{
	ll x;
	ll y;
	PO(ll a, ll b)
	{
		x = a;
		y = b;
	}
	PO() {}
};
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll t;
	cin >> t;
	while (t--)
	{
		PO poll[4];
		ll n, m;
		cin >> n >> m;
		ll black = 0;
		ll white = 0;
		if (n * m % 2 == 0)
		{
			black = white = n * m / 2;
		} else
		{
			black = n * m / 2;
			white = black + 1;
		}
		cin >> poll[0].x >> poll[0].y >> poll[1].x >> poll[1].y;
		cin >> poll[2].x >> poll[2].y >> poll[3].x >> poll[3].y;
		ll x1 = max(poll[0].x, poll[2].x), x2 = min(poll[1].x, poll[3].x);
		ll x = x2 - x1 + 1;
		x = x < 0 ? 0 : x;
		ll y1 = max(poll[0].y, poll[2].y), y2 = min(poll[1].y, poll[3].y);
		ll y = y2 - y1 + 1;
		y = y < 0 ? 0 : y;
		ll s = x * y;
		s = s < 0 ? 0 : s;
		ll sb = (poll[3].x - poll[2].x + 1) * (poll[3].y - poll[2].y + 1);
		if (sb % 2 == 0)
		{
			black += sb / 2;
			white -= sb / 2;
		} else
		{
			if ((poll[2].x % 2 == 0 && poll[2].y % 2 == 0) || (poll[2].x % 2 != 0 && poll[2].y % 2 != 0))
			{
				black += sb / 2 + 1;
				white -= sb / 2 + 1;
			} else
			{
				black += sb / 2;
				white -= sb / 2;
			}
		}
		ll sw = (poll[1].x - poll[0].x + 1) * (poll[1].y - poll[0].y + 1);
		ll lsw = sw - s;
		ll w1 = sw / 2;
		ll b1 = sw / 2;
		if (sw % 2 != 0)
		{
			if ((poll[0].x % 2 == 0 && poll[0].y % 2 == 0) || (poll[0].x % 2 != 0 && poll[0].y % 2 != 0))
			{
				b1 = sw / 2;
				w1 = sw / 2 + 1;
			} else
			{
				b1 = sw / 2 + 1;
				w1 = sw / 2;
			}
		}
		if (lsw > 0)
		{
			if (s % 2 != 0)
			{
				if ((x1 % 2 == 0 && y1 % 2 == 0) || (x1 % 2 != 0 && y1 % 2 != 0))
				{
					b1 -= s / 2;
					w1 -= s / 2 + 1;
				} else
				{
					b1 -= s / 2 + 1;
					w1 -= s / 2;
				}
			} else
			{
				b1 -= s / 2;
				w1 -= s / 2;
			}
		} else
		{
			b1 = 0;
			w1 = 0;
		}
		cout << white + b1 << " " << black - b1 << endl;
	}
	return 0;
}
