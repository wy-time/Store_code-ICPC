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
const int maxn = 2e5 + 5;
int num[maxn];
int ans[maxn];
int vis[maxn];
int n;
int dfs(int now, int aim)
{
	if (num[now] % 2 == aim)
	{
		return 1;
	} else if (ans[now] != 0)
	{
		if (ans[now] != -1)
			return ans[now] + 1;
		else
			return -1;
	} else
	{
		int minans = 100000000;
		if (now + num[now] <= n && !vis[now + num[now]])
		{
			vis[now + num[now]] = 1;
			int t = dfs(now + num[now], aim);
			vis[now + num[now]] = 0;
			if (t != -1)
			{
				minans = min(t, minans);
				// return t + 1;
			}
		}
		if (now - num[now] > 0 && !vis[now - num[now]])
		{
			vis[now - num[now]] = 1;
			int t = dfs(now - num[now], aim);
			vis[now - num[now]] = 0;
			if (t != -1)
			{
				minans = min(t, minans);
			}
		}
		if (minans != 100000000)
		{
			ans[now] = minans;
			return ans[now] + 1;
		}
	}
	ans[now] = -1;
	return -1;
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
	cin >> n;
	int i;
	wfor(i, 1, n + 1)
	{
		cin >> num[i];
	}
	wfor(i, 1, n + 1)
	{
		if (ans[i] == 0)
		{
			dfs(i, (num[i] % 2) ^ 1);
		}
	}
	wfor(i, 1, n + 1)
	cout << ans[i] << " ";
	cout << endl;
	return 0;
}
