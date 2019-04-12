#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 1e6 + 5;
ll prime[maxn];
void getprime()
{
	ll i;
	wfor(i, 2, maxn)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		ll j;
		for (j = 1; j <= prime[0] && i * prime[j] < maxn; j++)
		{
			prime[prime[j]*i] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
vector<ll> v;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll t;
	cin >> t;
	getprime();
	ll casecnt = 0;
	while (t--)
	{
		v.clear();
		casecnt++;
		ll n;
		cin >> n;
		ll i;
		int fu = 0;
		if (n < 0)
		{
			n = -n;
			fu = 1;
		}
		ll tmp = n;
		for (i = 1; i <= prime[0] && prime[i] <= n; i++)
		{
			if (tmp % prime[i] == 0)
			{
				ll cnt = 0;
				while (tmp % prime[i] == 0)
				{
					cnt++;
					tmp /= prime[i];
				}
				v.push_back(cnt);
			}
		}
		sort(v.begin(), v.end(), greater<ll>());
		ll len = v.size();
		cout << "Case " << casecnt << ": ";
		if (len >= 1)
		{
			ll cnt = v[0];
			wfor(i, 1, len)
			{
				cnt = gcd(cnt, v[i]);
			}
			if (fu)
			{
				while (cnt % 2 == 0)
					cnt /= 2;
			}
			cout << cnt << endl;
		} else
			cout << 1 << endl;
	}
	return 0;
}