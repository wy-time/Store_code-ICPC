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
const ll maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
ll fac[maxn], inv[maxn];
ll ksm(ll a, ll b)
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
	return ans % mod;
}
void init()
{
	int i;
	fac[0] = 1;
	fac[1] = 1;
	wfor(i, 2, maxn)
	{
		fac[i] = fac[i - 1] % mod * i % mod;
	}
	inv[maxn - 1] = ksm(fac[maxn - 1], mod - 2);
	mfor(i, maxn - 1, 1)
	{
		inv[i - 1] = inv[i] * i % mod;
	}
}
ll comb(ll n, ll m)
{
	return fac[n] % mod * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	init();
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int i;
		wfor(i, 0, n - 1)
		{
			int a, b;
			cin >> a >> b;
		}
		if (m == 1)
			cout << 1 << endl;
		else
		{
			ll res = comb(n - 1, m - 1);
			res = res * fac[m] % mod;
			cout << res << endl;
		}
	}
	return 0;
}
