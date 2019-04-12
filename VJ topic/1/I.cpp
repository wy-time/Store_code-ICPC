#include <iostream>
#include <cstdio>
#include <cstring>
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
char ma[15][15];
int ma1[15][15];
int vis[15][15];
int n, m;
const int INF = 0x7f7f7f7f;
struct st1
{
	int x; int y;
	int step;
	st1(int a, int b, int c)
	{
		x = a;
		y = b;
		step = c;
	}
};
int bfs(int begx, int begy);
int bfs(int begx1, int begy1, int begx2, int begy2);
void dfs(int begx, int begy, int cnt);
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	cin >> t;
	int case_num = 1;
	while (t--)
	{
		memset(vis, 0, sizeof(vis));
		cin >> n >> m;
		int i, j;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				cin >> ma[i][j];
			}
		}
		int cnt = 1;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				if (!vis[i][j] && ma[i][j] == '#')
				{
					dfs(i, j, cnt);
					cnt++;
				}
			}
		}
		cnt--;
		if (cnt > 2)
			cout << "Case " << case_num << ": " << -1 << endl;
		else if (cnt > 0)
		{
			if (cnt == 2)
			{
				int mins = INF;
				memmove(ma1, vis, sizeof(vis));
				wfor(i, 0, n)
				{
					wfor(j, 0, m)
					{
						if (ma1[i][j] == 1)
						{
							mins = min(bfs(i, j), mins);
						}
					}
				}
				int mins2 = INF;
				wfor(i, 0, n)
				{
					wfor(j, 0, m)
					{
						if (ma1[i][j] == 2)
						{
							mins2 = min(bfs(i, j), mins2);
						}
					}
				}
				cout << "Case " << case_num << ": " << max(mins, mins2) << endl;
			} else
			{
				int mins = INF;
				memmove(ma1, vis, sizeof(vis));
				int k, l;
				wfor(k, 0, n)
				{
					wfor(l, 0, m)
					{
						if (ma1[k][l] == 1)
						{
							int begx = k;
							int begy = l;
							int tk = begy;
							wfor(i, begx, n)
							{
								if (i != begx)
									tk = 0;
								wfor(j, tk, m)
								{
									if (ma1[i][j] == 1)
									{
										mins = min(bfs(begx, begy, i, j), mins);
									}
								}
							}
						}
					}
				}
				cout << "Case " << case_num  << ": " << mins << endl;
			}
		} else
			cout << "Case " << case_num  << ": " << 0 << endl;
		case_num++;
	}
	return 0;
}
void dfs(int begx, int begy, int cnt)
{
	vis[begx][begy] = cnt;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int i;
	wfor(i, 0, 4)
	{
		int x = begx + dx[i];
		int y = begy + dy[i];
		if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && ma[x][y] == '#')
		{
			vis[x][y] = cnt;
			dfs(x, y, cnt);
		}
	}
}
int bfs(int begx, int begy)
{
	queue<st1>qu;
	qu.push(st1(begx, begy, 0));
	int vist[15][15] = {0};
	vist[begx][begy] = 1;
	int maxs = 0;
	while (!qu.empty())
	{
		st1 temp = qu.front();
		maxs = max(temp.step, maxs);
		qu.pop();
		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};
		int i;
		wfor(i, 0, 4)
		{
			int x = temp.x + dx[i];
			int y = temp.y + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && !vist[x][y] && ma1[x][y] != 0)
			{
				qu.push(st1(x, y, temp.step + 1));
				vist[x][y] = 1;
			}
		}
	}
	return maxs;
}
int bfs(int begx1, int begy1, int begx2, int begy2)
{
	queue<st1>qu;
	int vist[15][15] = {0};
	qu.push(st1(begx1, begy1, 0));
	vist[begx1][begy1] = 1;
	if (!vist[begx2][begy2])
	{
		qu.push(st1(begx2, begy2, 0));
		vist[begx2][begy2] = 1;
	}
	int maxs = 0;
	while (!qu.empty())
	{
		st1 temp = qu.front();
		qu.pop();
		maxs = max(temp.step, maxs);
		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};
		int i;
		wfor(i, 0, 4)
		{
			int x = temp.x + dx[i];
			int y = temp.y + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && !vist[x][y] && ma1[x][y] == 1)
			{
				qu.push(st1(x, y, temp.step + 1));
				vist[x][y] = 1;
			}
		}
	}
	return maxs;
}
// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<string>
// #include<cstdio>
// #include<queue>
// using  namespace std;
// #define inf 0x3f3f3f

// struct Point
// {
// 	int x;
// 	int y;
// };

// int n, m;
// char map[15][15];
// int dis[15][15];
// queue<Point>que;
// int dirx[4] = { 1, -1, 0, 0 };
// int diry[4] = { 0, 0, -1, 1 };

// int bfs(int x1, int y1, int x2, int y2)
// {
// 	int xx, yy;
// 	Point p1, p2, cur, nex;
// 	memset(dis, inf, sizeof(dis));
// 	p1.x = x1; p1.y = y1;
// 	p2.x = x2; p2.y = y2;
// 	dis[x1][y1] = 0;
// 	dis[x2][y2] = 0;
// 	que.push(p1);
// 	que.push(p2);
// 	while (!que.empty())
// 	{
// 		cur = que.front();
// 		que.pop();
// 		for (int i = 0; i < 4; i++)
// 		{
// 			xx = cur.x + dirx[i];
// 			yy = cur.y + diry[i];
// 			if (xx >= 0 && xx < n && yy >= 0 && yy < m && map[xx][yy] == '#' && dis[xx][yy] > dis[cur.x][cur.y] + 1)
// 			{
// 				dis[xx][yy] = dis[cur.x][cur.y] + 1;
// 				nex.x = xx;
// 				nex.y = yy;
// 				que.push(nex);
// 			}
// 		}
// 	}
// 	int maxx = 0;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0 ; j < m; j++)
// 			if (map[i][j] == '#')
// 			{
// 				maxx = max(maxx, dis[i][j]);
// 			}
// 	return maxx;
// }

// int main()
// {
// 	int casen;
// 	cin >> casen;
// 	for (int cas = 1; cas <= casen; cas++)
// 	{
// 		while (!que.empty())
// 			que.pop();
// 		cin >> n >> m;

// 		for (int i = 0; i < n; i++)
// 			cin >> map[i];

// 		int temp;
// 		int ans = inf;
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < m; j++)
// 				if (map[i][j] == '#')
// 					for (int ii = 0; ii < n; ii++)
// 						for (int jj = 0; jj < m; jj++)
// 							if (map[ii][jj] == '#')
// 							{
// 								temp = bfs(i, j, ii, jj);
// 								ans = min(ans, temp);
// 							}
// 		if (ans == inf) ans = -1;     //枚举的各个点都存在有草没烧到
// 		cout << "Case " << cas << ": " << ans << endl;
// 	}
// }
