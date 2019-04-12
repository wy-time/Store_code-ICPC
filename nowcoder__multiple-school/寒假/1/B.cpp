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
	ll n;
	ll num[5] = {0};
	cin >> n;
	ll i;
	wfor(i, 0, n)
	{
		ll t;
		cin >> t;
		num[t]++;
	}
	ll flag = 1;
	ll last = 0;
	ll ans = 0;
	wfor(i, 0, n)
	{
		if (flag == 1)
		{
			if (num[4] != 0)
			{
				ans += (4 - last) * (4 - last);
				last = 4;
				num[4]--;
			} else if (num[2] != 0)
			{
				ans += (2 - last) * (2 - last);
				last = 2;
				num[2]--;
			} else
			{
				ans += (0 - last) * (0 - last);
				last = 0;
				num[0]--;
			}
		} else
		{
			if (num[0] != 0)
			{
				ans += (0 - last) * (0 - last);
				last = 0;
				num[0]--;
			} else if (num[2] != 0)
			{
				ans += (2 - last) * (2 - last);
				last = 2;
				num[2]--;
			} else
			{
				ans += (4 - last) * (4 - last);
				last = 4;
				num[4]--;
			}
		}
		flag *= -1;
	}
	cout << ans << endl;
	return 0;
}
