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
const int mod = 998244353;
ll ksm(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
ll fac[105];
ll inv[105];
void init()
{
	fac[0] = fac[1] = inv[1] = inv[0] = 1;
	int i;
	wfor(i, 2, 105)
	{
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[104] = ksm(fac[104], mod - 2);
	mfor(i, 103, 2)
	{
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
}
ll comb(ll a, ll b)
{
	return fac[a] * inv[b] % mod * inv[a - b] % mod;
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
	int m;
	cin >> m;
	int i;
	ll ans = 0;
	init();
	// cout << inv[103]*fac[103] % mod << endl;
	// cout << comb(2, 0) << endl;
	wfor(i, 0, m + 1)
	{
		ans = ans + ksm(2, m - i) * comb(m, i) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
