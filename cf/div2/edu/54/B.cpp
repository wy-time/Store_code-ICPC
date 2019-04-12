#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 1e5 + 5;
ll prime[maxn];
void get_prime()
{
	ll i;
	wfor(i, 2, maxn)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		ll j;
		for (j = 1; j <= prime[0] && i * prime[j] < maxn; j++)
		{
			prime[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
// ll ans[maxn];
// ll pos[maxn];
// ll ksm(ll a, ll b)
// {
// 	ll ans = 1;
// 	while (b)
// 	{
// 		if (b & 1)
// 			ans *= a;
// 		a *= a;
// 		b >>= 1;
// 	}
// 	return ans;
// }
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll n;
	cin >> n;
	get_prime();
	ll i;
	ll ans = 0;
	ll flag = 0;
	if (n % 2 == 0)
		cout << n / 2 << endl;
	else
	{
		for (i = 1; i <= prime[0] && prime[i] <= n; i++)
		{
			if (n % prime[i] == 0)
			{
				// cnt++;
				while (n % prime[i] == 0)
				{
					// ans[cnt]++;
					// pos[cnt] = i;
					ans = n - prime[i];
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		if (n > 1 && ans == 0)
		{
			cout << 1 << endl;
			return 0;
		}
		cout << ans / 2 + 1 << endl;
		// ll res = 0;
		// wfor(i, 1, cnt + 1)
		// {
		// 	ll t = ksm(prime[pos[i]], ans[i] - 1);
		// 	res += tmp / t;
		// 	tmp /= t;
		// }
		// cout << res << endl;

	}
	return 0;
}
