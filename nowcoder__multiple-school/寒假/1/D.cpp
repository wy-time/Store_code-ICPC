#include <iostream>
#include <cmath>
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
const ll mod = 1e9 + 7;
const ll phmod = 1e9 + 6;
long long phi(long long x)
{
	int res = x, a = x;
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			res = res / i * (i - 1); //res -= res/i;
			while (a % i == 0)a /= i;
		}
	}
	if (a > 1)res = res / a * (a - 1); //res -= res/a;
	return res;
}
ll gcd(ll a , ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
ll pow(ll a, ll b)
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
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	a %= mod;
	b %= mod;
	k %= mod;
	ll phd = n * phi(n) / 2;
	ll t1 = pow(k, phd % phmod + phmod);
	// ll t2 = pow(k, (n - i));
	a = a * t1 % mod;
	// a = a * t2 % mod;
	// b = b * t2 % mod;
	b = b * t1 % mod;
	cout << (a + b) % mod << endl;
	return 0;
}
