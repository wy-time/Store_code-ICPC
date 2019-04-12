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
int l, n, m;
char ma[35][35][35];
int vis[35][35][35];
struct Point
{
	int z;
	int x;
	int y;
	int step;
	Point() {}
	Point(int a, int b, int c, int d)
	{
		z = a; x = b; y = c; step = d;
	}
};
int bfs(Point beg);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	while (cin >> l >> n >> m)
	{
		if (l == 0 && n == 0 && m == 0)
			break;
		int i, j, k;
		Point beg;
		memset(vis, 0, sizeof(vis));
		wfor(i, 0, l)
		{
			wfor(j, 0, n)
			{
				wfor(k, 0, m)
				{
					cin >> ma[i][j][k];
					if (ma[i][j][k] == 'S')
						beg = Point(i, j, k, 0);
				}
			}
		}
		int res = -1;
		res = bfs(beg);
		if (res == -1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " << res << " minute(s)." << endl;

	}
	return 0;
}
int bfs(Point beg)
{
	queue<Point>qu;
	qu.push(beg);
	vis[beg.z][beg.x][beg.y] = 1;
	int dl[6] = {0, 0, 0, 0, - 1, 1};
	int dx[6] = {0, 1, 0, -1, 0, 0};
	int dy[6] = {1, 0, -1, 0, 0, 0};
	while (!qu.empty())
	{
		Point temp = qu.front();
		qu.pop();
		int i;
		wfor(i, 0, 6)
		{
			int z, x, y;
			z = temp.z + dl[i];
			x = temp.x + dx[i];
			y = temp.y + dy[i];
			if (z >= 0 && z < l && x >= 0 && x < n && y >= 0 && y < m && (ma[z][x][y] == '.' || ma[z][x][y] == 'E') && !vis[z][x][y])
			{
				if (ma[z][x][y] == 'E')
					return temp.step + 1;
				qu.push(Point(z, x, y, temp.step + 1));
				vis[z][x][y] = 1;
			}
		}
	}
	return -1;
}