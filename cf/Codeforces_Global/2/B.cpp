#include <iostream>
#include <cstring>
#include <algorithm>
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
const ll maxn = 1005;
ll num[maxn];
ll check(ll n, ll h)
{
	ll i;
	ll temp[maxn];
	memcpy(temp, num, sizeof(num));
	sort(temp, temp + n, greater<ll>());
	ll high = 0;
	wfor(i, 0, n)
	{
		if (i + 1 < n)
		{
			high += max(temp[i], temp[i + 1]);
			i++;
		}
		else
			high += temp[i];
	}
	if (high <= h)
		return 1;
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
	ll n, h;
	cin >> n >> h;
	ll i;
	wfor(i, 0, n)
	{
		cin >> num[i];
	}
	ll l = 0, r = n;
	while (l <= r)
	{
		ll mid = (l + r) >> 1;
		if (check(mid, h) == 1)
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << r << endl;
	return 0;
}
