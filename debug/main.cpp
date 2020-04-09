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
int check (ll x, ll k, ll n)
{
	ll sum = x;
	while (x / k > 0)
	{
		sum += x / k;
		k *= k;
		if (sum >= n)
			break;
	}
	if (sum >= n)
		return 1;
	else
		return 0;
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
	ll n, k;
	cin >> n >> k;
	ll l = 0, r = n;
	while (l <= r)
	{
		ll mid = (l + r) >> 1;
		if (check(mid, k, n) == 1)
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
