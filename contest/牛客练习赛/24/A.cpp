#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
ll ksm(ll a, ll b);
const ll mod = 1000000007;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	ll res = m;
	res = res % mod * ksm(m - 1, n - 1) % mod;
	cout << res % mod << endl;
	return 0;
}
ll ksm(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans % mod * a % mod) % mod;
		a = a % mod * a % mod;
		b >>= 1;
	}
	return ans;
}