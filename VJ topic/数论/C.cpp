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
const int maxn = 1e6 + 5;
ll prime[maxn + 1];
void getprime()
{
	int i;
	wfor(i, 2, maxn + 1)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		int j;
		for (j = 1; j <= prime[0] && prime[j] <= maxn / i; ++j)
		{
			prime[prime[j]*i] = 1;
			if (prime[j] % i == 0)
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
		int i;
		ll ans = 1;
		for (i = 1; prime[i] * prime[i] <= n; i++)
		{
			if (n % prime[i] == 0)
			{
				ll cnt = 0;
				while (n % prime[i] == 0)
				{
					n /= prime[i];
					cnt++;
				}
				ans *= (cnt + 1);
			}
		}
		if (n != 1)
			ans *= 2;
		ans--;
		cout << "Case " << casecnt << ": " << ans << endl;
	}
	return 0;
}
