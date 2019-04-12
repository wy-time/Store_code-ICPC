#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
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
struct st
{
	int x;
	int y;
	st() {}
	st(int a, int b)
	{
		x = a;
		y = b;
	}
};
int dis[10][10];
int ma[10][10];
int vis[10][10];
int n = 5;
st path[10][10];
void bfs();
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif

	int i, j;
	wfor(i, 0, n)
	{
		wfor(j, 0, n)
		{
			cin >> ma[i][j];
		}
	}
	memset(path, -1, sizeof(path));
	bfs();
	int x = 4; int y = 4;
	stack<st>sta;
	sta.push(st(x, y));
	while (path[x][y].x != -1)
	{
		sta.push(path[x][y]);
		st temp = path[x][y];
		x = temp.x;
		y = temp.y;
	}
	while (!sta.empty())
	{
		cout << "(" << sta.top().x << ", " << sta.top().y << ")" << endl;
		sta.pop();
	}
	return 0;
}
void bfs()
{
	queue<st>qu;
	qu.push(st(0, 0));
	vis[0][0] = 1;
	dis[0][0] = 0;
	while (!qu.empty())
	{
		st temp = qu.front();
		qu.pop();
		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};
		int i;
		wfor(i, 0, 4)
		{
			int x = temp.x + dx[i];
			int y = temp.y + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < n && ma[x][y] == 0 && !vis[x][y])
			{
				vis[x][y] = 1;
				dis[x][y] = dis[temp.x][temp.y] + 1;
				qu.push(st(x, y));
				path[x][y] = temp;
			}
		}
	}
}