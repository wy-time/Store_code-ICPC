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
int dp[5][1005][2];
int room[1005];
char [5];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int i;
		wfor(i, 0, n)
		{
			cin >> room[i];
		}
		wfor(i, 0, m)
		{
			cin >> zu[i];
		}
		int j;
		wfor(i, 0, 5)
		{
			wfor(j, 0, 1005)
			{
				if (zu[i] == '+')
					dp[i][j] = max(dp[i - 1][j][0] + room[j], dp[i - 1][j][0]);
			}
		}
	}
	return 0;
}
