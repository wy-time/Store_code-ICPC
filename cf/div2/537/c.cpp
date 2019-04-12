#include <iostream>
#include <cmath>
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
const ll maxn = 1e5 + 5;
ll num[maxn];
ll n, k, a, b;
ll slove(ll l, ll r)
{
	if (r == l)
	{
		ll pos1 = upper_bound(num, num + k, r) - num;
		ll pos2 = lower_bound(num, num + k, l) - num;
		ll pos = pos1 - pos2;
		if (num[pos2] != r)
		{
			return a;
		} else
			return 1ll * b * pos;
	}
	ll mid = (l + r) >> 1;
	ll pos1 = upper_bound(num, num + k, r) - num;
	ll pos2 = lower_bound(num, num + k, l) - num;
	ll pos = pos1 - pos2;
	ll ans;
	if (pos == 0)
	{
		ans = a;
		return ans;
	} else
	{
		ans = 1ll * (r - l + 1) * b * pos;
		ans = min(ans, (slove(l, mid) + slove(mid + 1, r)));
	}
	return ans;
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
	cin >> n >> k >> a >> b;
	ll i;
	wfor(i, 0, k)
	{
		cin >> num[i];
	}
	sort(num, num + k);
	ll ans = slove(1, pow(2, n));
	cout << ans << endl;
	return 0;
}
