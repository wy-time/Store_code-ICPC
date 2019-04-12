#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll n, m;
	cin >> n >> m;
	ll i;
	// ll j;
	// ll a[105] = {0};
	ll t = m;
	wfor(i, 0, n)
	{
		ll t2;
		cin >> t2;
		t = gcd(t, t2);
	}
	cout << m / t << endl;
	return 0;
}
