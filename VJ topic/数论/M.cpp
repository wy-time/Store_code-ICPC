#include <cstring>
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
int prime[maxn + 1];
void getprime()
{
	int i;
	wfor(i, 2, maxn + 1)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		int j;
		for (j = 1; j <= prime[0] && prime[j]*i <= maxn; j++)
		{
			prime[i * prime[j]] = 1;
			if (prime[j] % i == 0)
				break;
		}
	}
}
int isprime[100005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	getprime();
	int t;
	cin >> t;
	int casecnt = 0;
	while (t--)
	{
		casecnt++;
		memset(isprime, 1, sizeof(isprime));
		ll a, b;
		cin >> a >> b;
		int i;
		wfor(i, 1, prime[0] + 1)
		{
			if (prime[i]*prime[i] > b)
				break;
			ll t = 0;
			if (a / prime[i] < 2)
				t = prime[i] * 2;
			else
			{
				t = ((a - 1) / prime[i] + 1) * prime[i];
			}
			while (t <= b)
			{
				isprime[t - a] = 0;
				t += prime[i];
			}
		}
		int sz = b - a + 1;
		int ans = 0;
		wfor(i, 0, sz)
		{
			if (isprime[i])
				ans++;
		}
		if (a == 1)
			ans--;
		cout << "Case " << casecnt << ": " << ans << endl;
	}
	return 0;
}
