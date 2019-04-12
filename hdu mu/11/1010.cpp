#include <iostream>
#include <cstdio>
// #include <vector>
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
int dp[2][100005];
struct st
{
	int x;
	int y;
	int v;
};
st vil[100005];
// vector<int> v[100005];
struct rule
{
	bool operator()(const st &a, const st &b)
	{
		if (a.x == b.x)
			return a.y < b.y;
		else
			return a.x < b.x;
	}
};
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
		int n;
		int maxn = 0;
		cin >> n;
		int i;
		wfor(i, 0, n)
		{
			cin >> vil[i].x >> vil[i].y >> vil[i].v;
		}
		sort(vil, vil + n, rule());
		int cnt=1;
		int temp=vil[0].x;
		wfor(i,0,n)
		{
			if(temp!=vil[i].x)
			{
				temp=vil[i].x;
				cnt++;
			}
			vil[i].x=cnt;
		}
		int j = 1;
		wfor(i, 1, n + 1)
		{
			dp[1][i] = max(dp[j % 2][i - 1], max(dp[(j - 1) % 2][i], dp[(j - 1) % 2][i - 1] + vil[i].v));
		}
		// int t = vil[0].x;
		// int temp = 0;
		// wfor(i, 0, n)
		// {
		// 	if (t != vil[i].x)
		// 	{
		// 		temp++;
		// 	}
		// 	v[temp].push_back(vil[i].y);
		// }
		// int j;
		// int cnt = 0;
		// wfor(i, 1, temp + 1)
		// {
		// 	for (j = 1; j < v[i - 1].size() + 1; j++)
		// 	{
		// 		dp[i][j] = max(dp[i - 1][j - 1] + vil[cnt].v, max(dp[i][j - 1], dp[i - 1][j]));
		// 		maxn = max(maxn, dp[i][j]);
		// 		cnt++;
		// 	}
		// }
		cout << dp[1][i - 1] << endl;
	}
	return 0;
}
