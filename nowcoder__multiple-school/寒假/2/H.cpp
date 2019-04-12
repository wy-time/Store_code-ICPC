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
const ll maxn = 1e6 + 5;
ll prime[maxn + 1];
void getprime()
{
	ll i;
	wfor(i, 2, maxn + 1)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		ll j;
		for (j = 1; j <= prime[0] && prime[j]*i <= maxn; j++)
		{
			prime[i * prime[j]] = 1;
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
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	getprime();
	int i;
	wfor(i, 1, 2001)
	{
		cout << prime[i]*prime[4001 - i] << endl;
	}
	return 0;
}