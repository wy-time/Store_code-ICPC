#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 100 + 5;
int prime[maxn + 1];
void getprime()
{
	int i;
	for (i = 2; i <= maxn; i++)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		int j;
		for (j = 1; j <= prime[0] && prime[j]*i <= maxn; j++)
		{
			prime[prime[j]*i] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	// freopen("F:\\Desktop\\question\\in.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	int ans[105] = {0};
	int casecnt = 0;
	getprime();
	while (t--)
	{
		memset(ans, 0, sizeof(ans));
		casecnt++;
		int cnt = 0;
		int n;
		cin >> n;
		int i;
		for (i = 1; prime[i] <= n; i++)
		{
			int temp = n;
			while (1)
			{
				ans[prime[i]] += temp / prime[i];
				temp /= prime[i];
				if (temp == 0)
					break;
			}
		}
		wfor(i, 2, 101)
		{
			if (ans[i] != 0)
				cnt++;
		}
		cout << "Case " << casecnt << ": " << n << " = ";
		int first = 1;
		wfor(i, 2, 101)
		{
			if (first)
			{
				if (ans[i] != 0 && cnt > 1)
				{
					cnt--;
					cout << i << " (" << ans[i] << ") ";
					first = 0;
				} else if (ans[i] != 0)
				{
					cnt--;
					cout << i << " (" << ans[i] << ")";
					first = 0;
				}
			} else
			{
				if (ans[i] != 0 && cnt > 1)
				{
					cnt--;
					cout << "* " << i << " (" << ans[i] << ") ";
				} else if (ans[i] != 0)
					cout << "* " << i << " (" << ans[i] << ")";
			}
		}
		cout << endl;
	}
	return 0;
}