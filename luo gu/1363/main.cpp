#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int flag;
char ma[1505][1505];
void dfs(int begx, int begy, int nowx, int nowy);
int n, m;
int vis [1505][1505][3];
int main()
{
	std::ios::sync_with_stdio(false);
	while (cin >> n >> m)
	{
		flag = 0;
		memset(vis, false, sizeof(vis));
		int i, j;
		int begx, begy;
		wfor(i, 0, n )
		{
			wfor(j, 0, m)
			{
				cin >> ma[i][j];
				if (ma[i][j] == 'S')
				{
					begx = i;
					begy = j;
				}
			}
		}
		dfs(begx, begy, begx, begy);
		if (flag)
		{
			cout << "Yes" << endl;
		} else
		{
			cout << "No" << endl;
		}
	}

	return 0;
}
void dfs(int begx, int begy, int nowx, int nowy)
{
	if (vis[begx][begy][0] == 1)
	{
		flag = 1;
		return ;
	}
	vis[begx][begy][0] = 1;
	vis[begx][begy][1] = nowx;
	vis[begx][begy][2] = nowy;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int i;
	wfor(i, 0, 4)
	{
		int x = begx + dx[i];
		int y = begy + dy[i];
		x = (x + n) % n, y = (y + m) % m;
		if ((ma[x][y] == '.' || ma[x][y] == 'S') && (!vis[x][y][0] || vis[x][y][1] != nowx + dx[i] || vis[x][y][2] != nowy + dy[i]))
		{
			dfs(x, y, nowx + dx[i], nowy + dy[i]);
			if (flag == 1)
				return;
		}
	}
}