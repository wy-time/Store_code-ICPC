#include <iostream>
#include <cstdio>
#include<cstring>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int n, m;
char ma[205][205];
int dis1[205][205];
int dis2[205][205];
int vis[205][205];
void bfs(int begx, int begy);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	while (cin >> n >> m)
	{
		int i, j;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				cin >> ma[i][j];
			}
		}
		memset(dis1, -1, sizeof(dis1));
		memset(dis2, -1, sizeof(dis2));
		bool flag = true;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				if (ma[i][j] == 'Y' || ma[i][j] == 'M')
				{
					memset(vis, 0, sizeof(vis));
					bfs(i, j);
					if (flag)
					{
						memmove(dis1, dis2, sizeof(dis2));
						flag = false;
					}
				}
			}
		}
		int res = 0x7f7f7f7f;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				if (ma[i][j] == '@' && dis1[i][j] != -1)
				{
					res = min(res, (dis1[i][j] + dis2[i][j]) * 11);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
void bfs(int begx, int begy)
{
	queue<int>qu;
	vis[begx][begy] = 1;
	qu.push(begx); qu.push(begy);
	dis2[begx][begy] = 0;
	while (!qu.empty())
	{
		int x1 = qu.front();
		qu.pop();
		int y1 = qu.front();
		qu.pop();
		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};
		int i;
		wfor(i, 0, 4)
		{
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && (ma[x][y] == '.' || ma[x][y] == '@' || ma[x][y] == 'M' || ma[x][y] == 'Y'))
			{
				qu.push(x);
				qu.push(y);
				dis2[x][y] = dis2[x1][y1] + 1;
				vis[x][y] = 1;
			}
		}
	}
}