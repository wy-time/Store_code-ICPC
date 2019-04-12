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
ll ksm(ll a, ll b, ll mod)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll t;
	cin >> t;
	ll casecnt = 0;
	while (t--)
	{
		casecnt++;
		ll n, k, mod;
		cin >> n >> k >> mod;
		ll i;
		ll cnt = ksm(n, k - 1, mod);
		cnt = cnt * k % mod;
		ll num[1005] = {0};
		wfor(i, 0, n)
		{
			cin >> num[i];
		}
		ll res = 0;
		wfor(i, 0, n)
		{
			res = (res % mod + cnt * num[i] % mod) % mod;
		}
		cout << "Case " << casecnt << ": " << res << endl;
	}
	return 0;
}
