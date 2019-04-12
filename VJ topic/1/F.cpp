#include <iostream>
#include <cstdio>
#include <queue>
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
int prime[10005];
int vis [10005];
int dis[10005];
void bfs(int beg, int _end);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	prime[2] = 1;
	int i, j;
	wfor(i, 3, 10005)
	{
		int flag = 1;
		for (j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			prime[i] = 1;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		memset(dis, -1, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		bfs(n, m);
		if (dis[m] != -1)
			cout << dis[m] << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}
void bfs(int beg, int _end)
{
	queue<int>qu;
	qu.push(beg);
	dis[beg] = 0;
	vis[beg] = 1;
	while (!qu.empty())
	{
		int now = qu.front();
		int temp = now;
		qu.pop();
		int a[4] = {0};
		int i;
		mfor(i, 3, 0)
		{
			a[i] = temp % 10;
			temp /= 10;
		}
		int j;
		wfor(i, 0, 4)
		{
			int t = a[i];
			wfor(j, 0, 10)
			{
				if (i != 0 || j != 0)
					a[i] = j;
				else
					continue;
				int change = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
				if (!vis[change] && prime[change])
				{
					dis[change] = dis[now] + 1;
					if (change == _end)
						return;
					qu.push(change);
					vis[change] = 1;
				}
			}
			a[i] = t;
		}
	}
}