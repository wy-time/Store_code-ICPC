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
const int maxn = 1e7 + 5;
int prime[5000005];
bool notprime[maxn];
void getprime()
{
	ll i;
	wfor(i, 2, maxn)
	{
		if (!notprime[i])
			prime[++prime[0]] = i;
		ll j;
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
		int n;
		cin >> n;
		int i;
		int res = 0;
		for (i = 1; i <= prime[0] && prime[i] <= n / 2; i++)
		{
			if (!notprime[n - prime[i]])
				res++;
		}
		cout << "Case " << casecnt << ": " << res << endl;
	}
	return 0;
}
