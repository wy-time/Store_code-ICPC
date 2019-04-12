#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct st
{
	int x;
	int y;
	int z;
};
st info [200];
struct rule
{
	bool operator()(const st&a, const st &b)
	{
		if (a.x != b.x)
			return a.x < b.x;
		else
			return a.y < b.y;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	int casecnt = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		casecnt++;
		int i;
		int cnt = 0;
		wfor(i, 0, n)
		{
			int a, b, c;
			cin >> a >> b >> c;
			info[cnt].x = a, info[cnt].y = b, info[cnt++].z = c;
			info[cnt].x = a, info[cnt].y = c, info[cnt++].z = b;
			info[cnt].x = b, info[cnt].y = c, info[cnt++].z = a;
			info[cnt].x = b, info[cnt].y = a, info[cnt++].z = c;
			info[cnt].x = c, info[cnt].y = a, info[cnt++].z = b;
			info[cnt].x = c, info[cnt].y = b, info[cnt++].z = a;
		}
		sort(info, info + 6 * n, rule());
		int j;
		int dp[200] = {0};
		int ans = 0;
		wfor(i, 0, n * 6)
		{
			dp[i] = info[i].z;
			wfor(j, 0, i)
			{
				if (j < i && info[j].x < info[i].x && info[j].y < info[i].y)
				{
					dp[i] = max(dp[j] + info[i].z, dp[i]);
				}
			}
			ans = max(ans, dp[i]);
		}
		cout << "Case " << casecnt << ": maximum height = " << ans << endl;
	}
	return 0;
}