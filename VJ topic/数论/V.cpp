#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 1e7 + 5;
int prime[1000005];
bool notprime[maxn];
void getprime()
{
	ll i;
	wfor(i, 2, maxn)
	{
		if (!notprime[i])
			prime[++prime[0]] = i;
		int j;
		for (j = 1; j <= prime[0] && prime[j]*i < maxn; j++)
		{
			notprime[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	int casecnt = 0;
	getprime();
	while (t--)
	{
		casecnt++;
		ll n;
		cin >> n;
		n *= 2;
		int i;
		ll res = 1;
		ll tmp = n;
		for (i = 1; i <= prime[0] && prime[i]*prime[i] <= n; i++)
		{
			ll cnt = 0;
			if (tmp % prime[i] == 0)
			{
				while (tmp % prime[i] == 0)
				{
					cnt++;
					tmp /= prime[i];
				}
				if (i != 1)
					res *= (cnt + 1);
			}
		}
		if (tmp > 1 && (tmp & 1))
			res *= 2;
		res--;
		cout << "Case " << casecnt << ": " << res << endl;
	}
	return 0;
}
