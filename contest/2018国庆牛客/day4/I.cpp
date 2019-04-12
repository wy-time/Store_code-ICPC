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
const ll mod = 998244353;
const int maxn = 1e7 + 5;
ll fac[maxn], inv[maxn];
ll ksm (ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans % mod * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
void init()
{
	int i;
	fac[0] = 1;
	fac[1] = 1;
	inv[0] = inv[1] = 1;
	wfor(i, 2, maxn)
	{
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[maxn - 1] = ksm(fac[maxn - 1], mod - 2);
	mfor(i, maxn - 1, 2)
	{
		inv[i - 1] = inv[i] * i % mod;
	}
}
ll comb(ll n, ll m)
{
	return fac[n] % mod * inv[m] % mod * inv[n - m] % mod;
}
ll ans[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	init();
	int n;
	cin >> n;
	int i;
	ll sum = 1;
	wfor(i, 0, n)
	{
		cin >> ans[i];
	}
	wfor(i, 0, n)
	{
		sum = sum * (ans[i] + 1) % mod;
	}
	wfor(i, 0, n)
	{
		sum = (sum + comb(ans[i] + 1, 2)) % mod;
	}
	cout << sum % mod << endl;
	return 0;
}
