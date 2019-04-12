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
struct st
{
	int x; int y;
	int step;
	st(int a, int b, int c)
	{
		x = a;
		y = b;
		step = c;
	}
};
char ma[1005][1005];
int ma1[1005][1005];
int vis[1005][1005];
void bfs(int begx, int begy);
int bfs1(int begx, int begy);
int n, m;
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int i, j;
		int begx; int begy;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				cin >> ma[i][j];
				if (ma[i][j] == 'J')
				{
					begx = i;
					begy = j;
				}
			}
		}
		memset(ma1, -1, sizeof(ma1));
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				if (ma[i][j] == 'F')
				{
					bfs(i, j);
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		int res = bfs1(begx, begy);
		if (res == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << res << endl;
	}
	return 0;
}
void bfs(int begx, int begy)
{
	queue<st>qu;
	qu.push(st(begx, begy, 0));
	ma1[begx][begy] = 0;
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
			if (x >= 0 && x < n && y >= 0 && y < m && (ma[x][y] == '.' || ma[x][y] == 'J') && (ma1[x][y] == -1 || ma1[x][y] > temp.step + 1))
			{
				vis[x][y] = 1;
				ma1[x][y] = temp.step + 1;
				qu.push(st(x, y, temp.step + 1));
			}
		}
	}
}
int bfs1(int begx, int begy)
{
	queue<st>qu;
	qu.push(st(begx, begy, 0));
	vis[begx][begy] = 1;
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
			if (x < 0 || x >= n || y < 0 || y >= m)
				return temp.step + 1;
			if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && (ma1[x][y] != -1 || ma[x][y] == '.') && (ma1[x][y] > temp.step + 1 || (ma1[x][y] == -1 && ma[x][y] == '.')))
			{
				vis[x][y] = 1;
				qu.push(st(x, y, temp.step + 1));
			}
		}
	}
	return -1;
}
// #include <iostream>
// #include <queue>
// #include <memory.h>
// #include <stdio.h>
// #define MAX 1100
// using namespace std;
// struct P//用来存储路径的节点
// {
// 	int r, c;
// 	int step;
// 	P(int _r, int _c, int _s)
// 	{
// 		r = _r, c = _c, step = _s;
// 	}
// 	P() {}
// };

// const int dr[] = {0, 0, 1, -1}; //构造函数
// const int dc[] = {1, -1, 0, 0};
// char Map[MAX][MAX];//存储地图
// int visit[MAX][MAX];//BFS中最重要的visit数组
// int times[MAX][MAX];//记录每个地方被烧到所需的时间
// int r, c; //行，列
// int Step;//记录最终逃脱所需的步数或时间
// P J;
// queue<P> q;//全局队列，这是本题的关键，也是一个大坑

// void clear_q()//用来清除队列中的数据
// {
// 	while (!q.empty())
// 		q.pop();
// }

// void show_time()//调试使用
// {
// 	for (int i = 0; i < r; i++)
// 	{
// 		for (int j = 0; j < c; j++)
// 		{
// 			cout << times[i][j] << ' ';
// 		}
// 		cout << endl;
// 	}
// }

// void bfs_fire()//预处理，求出每一个位置被烧到所需要花的时间
// {
// 	int i;
// 	int R, C, Time;
// 	while (!q.empty())
// 	{
// 		P temp = q.front();
// 		q.pop();
// 		//cout<<temp.r<<' '<<temp.c<<endl;
// 		for (i = 0; i < 4; i++)
// 		{
// 			R = temp.r + dr[i];
// 			C = temp.c + dc[i];
// 			Time = temp.step + 1;
// 			if (R >= 0 && R < r && C >= 0 && C < c && (Map[R][C] == '.' || Map[R][C] == 'J') && visit[R][C] == 0)
// 			{
// 				//cout<<R<<' '<<C<<endl;
// 				visit[R][C] = 1;
// 				q.push(P(R, C, Time));
// 				times[R][C] = Time;
// 			}
// 		}
// 	}
// }


// int bfs_joe()//逃跑路线，每走一个位置，不仅要看是否符合一般条件，还要用到上一步求出的时间
// {
// 	int i;
// 	int R, C, Time;
// 	clear_q();
// 	q.push(J);
// 	visit[J.r][J.c] = 1;
// 	while (!q.empty())
// 	{
// 		P temp = q.front();
// 		q.pop();
// 		//cout<<temp.r<<' '<<temp.c<<endl;
// 		if (temp.r == 0 || temp.r == (r - 1) || temp.c == 0 || temp.c == (c - 1))
// 		{
// 			Step = temp.step + 1;
// 			return 1;
// 		}
// 		for (i = 0; i < 4; i++)
// 		{
// 			R = temp.r + dr[i];
// 			C = temp.c + dc[i];
// 			Time = temp.step + 1;
// 			if (R >= 0 && R < r && C >= 0 && C < c && Map[R][C] == '.' && visit[R][C] == 0 && Time < times[R][C])
// 			{
// 				visit[R][C] = 1;
// 				q.push(P(R, C, Time));
// 			}
// 		}
// 	}
// 	return 0;
// }

// int main()
// {
// 	int i, j;
// 	int t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		clear_q();//清空队列
// 		cin >> r >> c;
// 		for (i = 0; i < r; i++)
// 		{
// 			cin >> Map[i];
// 			for (j = 0; j < c; j++)
// 			{
// 				if (Map[i][j] == 'F') //本题最最坑爹的地方，题意并没有直接对着火点的数量进行说明，但确实说了，隐含在portions 这个单词中，fuck，英文不好真捉急
// 				{
// 					q.push(P(i, j, 0));
// 					times[i][j] = 0;
// 					visit[i][j] = 1;
// 				}
// 				if (Map[i][j] == 'J')
// 				{
// 					J.r = i;
// 					J.c = j;
// 					J.step = 0;
// 				}
// 			}
// 		}

// 		for (i = 0; i < r; i++) //每个点的初始被烧所需的时间应该设为正无穷
// 		{
// 			for (j = 0; j < c; j++)
// 			{
// 				times[i][j] = 1000000007;
// 			}
// 		}
// 		memset(visit, 0, sizeof(visit)); //visit数组是两个BFS公用的，所以需要初始化一下
// 		bfs_fire();
// 		//show_time();
// 		memset(visit, 0, sizeof(visit));
// 		if (bfs_joe())
// 			cout << Step << endl;
// 		else
// 			cout << "IMPOSSIBLE" << endl;

// 	}
// 	return 0;
// }
