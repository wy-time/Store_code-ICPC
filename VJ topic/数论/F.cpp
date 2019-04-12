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
const int maxn = 1e6 + 5;
const int mod = 1000003;
ll fac[maxn];
ll inv[maxn];
ll ksm(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
void init()
{
	ll i;
	fac[0] = inv[0] = 1;
	inv[1] = fac[1] = 1;
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
ll comb(int n, int m)
{
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	init();
	int t;
	cin >> t;
	int casecnt = 0;
	while (t--)
	{
		casecnt++;
		int n, k;
		cout << fac[maxn - 2] << endl;
		cin >> n >> k;
		cout << "Case " << casecnt << ": " << comb(n, k) << endl;
	}
	return 0;
}
