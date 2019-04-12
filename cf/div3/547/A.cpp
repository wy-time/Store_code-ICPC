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
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	ll n, m;
	cin >> n >> m;
	int ans = 0;
	if (m % n == 0)
	{
		ll t = m / n;
		while (t % 2 == 0)
		{
			t /= 2;
			ans++;
		}
		while (t % 3 == 0)
		{
			t /= 3;
			ans++;
		}
		if (t != 1)
			cout << -1 << endl;
		else
			cout << ans << endl;
	} else
		cout << -1 << endl;
	return 0;
}
