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
int vis[100];
struct ST
{
	int a;
	int b;
};
ST info[100];
struct rule
{
	bool operator()(const ST &q, const ST &w)
	{
		return max(vis[q.a], vis[q.b]) < max(vis[w.a], vis[w.b]);
	}
};
int ans[100];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int i;
	wfor(i, 0, n)
	{
		int a, b;
		cin >> a >> b;
		info[i].a = a;
		info[i].b = b;
		vis[a]++;
		vis[b]++;
	}
	sort(info, info + n, rule());
	wfor(i, 0, n)
	{
		if (ans[info[i].a] == ans[info[i].b])
		{
			if (vis[info[i].a] < vis[info[i].b])
				ans[info[i].a]++;
			else
				ans[info[i].b]++;
		} else
		{
			if (ans[info[i].a] < ans[info[i].b])
				ans[info[i].a]++;
			else
				ans[info[i].b]++;
		}
	}
	int res = 0;
	wfor(i, 0, m + 1)
	{
		if (ans[i] != 0)
		{
			res += ans[i] * ans[i];
		}
	}
	cout << res << endl;
	return 0;
}
