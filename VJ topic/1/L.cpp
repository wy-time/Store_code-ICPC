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
int n, m;
char ma[105][105];
int vis[105][105];
void dfs(int begx, int begy);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	while (cin >> n >> m)
	{
		if (n == 0)
			break;
		int i, j;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				cin >> ma[i][j];
			}
		}
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				if (ma[i][j] == '@' && !vis[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
void dfs(int begx, int begy)
{
	vis[begx][begy] = 1;
	int dx[3] = {0, 1, -1};
	int dy[3] = {0, 1, -1};
	int i, j;
	wfor(i, 0, 3)
	{
		wfor(j, 0, 3)
		{
			int x = begx + dx[i];
			int y = begy + dy[j];
			if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && ma[x][y] == '@')
			{
				dfs(x, y);
			}
		}
	}
}