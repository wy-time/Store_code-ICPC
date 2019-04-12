#include <iostream>
#include <queue>
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
char ma[105][105];
int vis[105][105][2];
int n, m;
int dis[105][105][2];
void bfs(int begx, int begy)
{
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	dis[begx][begy][0] = 0;
	queue<int>qu;
	qu.push(begx);
	qu.push(begy);
	qu.push(0);
	vis[begx][begy][0] = 1;
	while (!qu.empty())
	{
		int x1 = qu.front();
		qu.pop();
		int y1 = qu.front();
		qu.pop();
		int status = qu.front();
		qu.pop();
		int i;
		wfor(i, 0, 4)
		{
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && ma[x][y] != '#')
			{
				int flag = 1;
				if (vis[x][y][status] == 1)
				{
					if (dis[x1][y1][status] + 1 >= dis[x][y][status])
						flag = 0;
				}
				if (flag == 1)
				{
					if (ma[x][y] == '.')
					{
						qu.push(x);
						qu.push(y);
						qu.push(status);
						vis[x][y][status] = 1;
						dis[x][y][status] = dis[x1][y1][status] + 1;
					} else if (ma[x][y] == '~')
					{
						if (status == 0)
						{
							qu.push(x);
							qu.push(y);
							qu.push(status);
							vis[x][y][status] = 1;
							dis[x][y][status] = dis[x1][y1][status] + 1;
						}
					} else if (ma[x][y] == 'w')
					{
						if (status == 1)
						{
							qu.push(x);
							qu.push(y);
							qu.push(status);
							dis[x][y][status] = dis[x1][y1][status] + 1;
							vis[x][y][status] = 1;
						}
					} else if (ma[x][y] == '@')
					{
						qu.push(x);
						qu.push(y);
						qu.push(0);
						vis[x][y][0] = 1;
						qu.push(x);
						qu.push(y);
						qu.push(1);
						vis[x][y][1] = 1;
						dis[x][y][status] = dis[x1][y1][status] + 1;
						if (status == 0)
							dis[x][y][1] = dis[x1][y1][0] + 2;
						else
							dis[x][y][0] = dis[x1][y1][1] + 2;
					} else if (ma[x][y] == 'T' || ma[x][y] == 'S')
					{
						qu.push(x);
						qu.push(y);
						qu.push(status);
						dis[x][y][status] = dis[x1][y1][status] + 1;
						vis[x][y][status] = 1;
					}
				}
			}
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
	cin >> n >> m;
	int i, j;
	wfor(i, 0, n)
	{
		wfor(j, 0, m)
		{
			cin >> ma[i][j];
		}
	}
	int begx, begy, endx, endy;
	wfor(i, 0, n)
	{
		wfor(j, 0, m)
		{
			if (ma[i][j] == 'S')
			{
				begx = i;
				begy = j;
			} else if (ma[i][j] == 'T')
			{
				endx = i;
				endy = j;
			}
		}
	}
	wfor(i, 0, 105)
	{
		wfor(j, 0, 105)
		{
			dis[i][j][0] = 0x7f7f7f7f;
			dis[i][j][1] = 0x7f7f7f7f;
		}
	}
	bfs(begx, begy);
	int ans = min(dis[endx][endy][0], dis[endx][endy][1]);
	if (ans != 0x7f7f7f7f)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}
