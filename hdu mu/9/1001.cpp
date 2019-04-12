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
// const int maxn = 7000;
// ll fac[maxn];
// ll inv[maxn];
// ll ksm(ll a, ll b);
// void init();
// ll get_com(ll n, ll m);
// ll mod;
// void exgcd (ll a1, ll b1, ll &x, ll &y);
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
		ll res = 1;
		int n, m, k;
		cin >> n >> m >> k;
		int i;
		int cnt = 0;
		wfor(i, 1, n * m + 1)
		{
			if (cnt < m)
			{

			}
		}
		// init();
		// int i;
		// wfor(i, 0, m)
		// {
		// 	res = res % mod * get_com(n * m - i * n, n) % mod * fac[n - 1] % mod;
		// }
		// res = res % mod * n % mod;
		// ll temp = 1;
		// wfor(i, 0, n)
		// {
		// 	temp = temp % mod * get_com(n * m - i * m, m) % mod * fac[m - 1] % mod;
		// }
		// temp = temp % mod * m % mod;
		// res = (res + temp) % mod;
		// res -= n * m;
		cout << res << endl;
	}
	return 0;
}
// ll ksm(ll a, ll b)
// {
// 	ll ans = 1;
// 	while (b)
// 	{
// 		if (b & 1)
// 			ans = ans % mod * a % mod;
// 		a = a % mod * a % mod;
// 		b >>= 1;
// 	}
// 	return ans % mod;
// }
// void init()
// {
// 	fac[0] = 1;
// 	int i;
// 	wfor(i, 1, maxn)
// 	{
// 		fac[i] = fac[i - 1] % mod * i % mod;
// 	}
// 	ll y = 0;
// 	mfor(i, maxn - 1, 0)
// 	{
// 		exgcd(fac[i], mod, inv[i], y);
// 		// inv[i] = inv[i + 1] % mod * (i + 1) % mod;
// 	}
// }
// ll get_com(ll n, ll m)
// {
// 	return (fac[n] * inv[m] % mod * inv[n - m] % mod) % mod;
// }
// void exgcd (ll a1, ll b1, ll &x, ll &y) //a1*x+b1*y=gcd
// {
// 	if (b1 == 0)
// 	{
// 		x = 1;
// 		y = 0;
// 	}
// 	else
// 	{
// 		exgcd(b1, a1 % b1, x, y);
// 		ll v = x;
// 		x = y;
// 		y = v - (a1 / b1) * y;
// 	}//逆元时a1为需要逆元数，b1为模，x为得数；&为引用，否则无法录入。。。应该没有二逼和我一样不知道吧。。
// }