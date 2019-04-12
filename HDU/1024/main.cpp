#include <iostream>
#include <cstring>
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
int num[maxn];
int dp[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int m, n;
	while (cin >> m >> n)
	{
		int i;
		memset(dp, 0, sizeof(dp));
		wfor(i, 1, n + 1)
		{
			cin >> num[i];
		}
		int j;
		wfor(i, 1, m + 1)
		{
			int temp = 0;
			int k;
			wfor(k, 1, i + 1)
			{
				temp += num[k];
			}
			dp[n] = temp;
			wfor(j, i + 1, n + 1)
			{
				temp = max(temp, dp[j - 1]) + num[j];
				dp[j - 1] = dp[n];
				dp[n] = max(temp, dp[n]);
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}
