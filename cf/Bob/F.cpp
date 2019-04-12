#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 1e6 + 5;
ll prime[maxn];
void get_prime()
{
	int i;
	wfor(i, 2, maxn)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		int j;
		for (j = 1; j <= prime[0] && prime[j]*i < maxn; j++)
		{
			prime[prime[j]*i] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int num[maxn];
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
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
	int t;
	cin >> t;
	int casecnt = 0;
	get_prime();
	int i;
	num[0] = 1e9;
	int cnt = 1;
	wfor(i, 1, prime[0] + 1)
	{
		num[cnt++] = prime[i];
	}
	for (i = 1; i <= prime[0]; i++)
	{
		int j;
		wfor(j, i, prime[0] + 1)
		{
			if (prime[i]*prime[j] <= 1000000)
				num[cnt++] = prime[i] * prime[j];
			else
				break;
		}
	}
	sort(num, num + cnt);
	while (t--)
	{
		casecnt++;
		int n;
		cin >> n;
		int pos = upper_bound(num, num + cnt, n) - num;
		// cout << pos << " " << cnt << endl;
		int ans = pos + 1;
		while (1)
		{
			int temp = gcd(ans, n);
			if (temp == 1)
				break;
			ans /= temp;
			n /= temp;
		}
		cout << "Case " << casecnt << ": " << ans << "/" << n << endl;
	}
	return 0;
}
