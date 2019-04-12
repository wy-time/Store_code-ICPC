#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll mod = 998244353;
ll ksm(ll a, ll b)
{
	if (b < 0)
		return 0;
	ll ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = ans % mod * a % mod;
		}
		b >>= 1;
		a = a % mod * a % mod;
	}
	return ans;
}
ll inv (int a)
{
	int i;
	ll ans = 1;
	wfor(i, 2, a + 1)
	{
		ans *= i;
	}
	ans = ksm(ans, mod - 2);
	return ans;
}
ll comb(ll a, ll b)
{
	if (b > a)
		return 0;
	ll i;
	ll ans = 1;
	mfor(i, a, a - b + 1)
	{
		ans = ans % mod * i % mod;
	}
	return ans * inv(b) % mod;
}

int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll n = a + b + c + d;
		comb(d, 1);
		ll res = ((((((comb(d, 2) * ksm(2, n - 2) % mod + comb(d, 1) * comb(b, 1) % mod * ksm(2, n - 2) % mod) % mod + comb(b, 2) * comb(c, 1) % mod * ksm(2, n - 3) % mod) % mod - comb(d, 3) * comb(b, 1) % mod * ksm(2, n - 4) % mod) % mod - comb(d, 1) * comb(b, 3) % mod * comb(c, 1) % mod * ksm(2, n - 5)) % mod - comb(d, 2) * comb(b, 2) % mod * comb(c, 1) % mod * ksm(2, n - 5) % mod) % mod + comb(d, 3) * comb(b, 3) % mod * comb(c, 1) % mod * ksm(2, n - 7) % mod) % mod;
		cout << ksm(2, n) - res << endl;
	}
	return 0;
}
