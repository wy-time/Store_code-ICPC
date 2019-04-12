// #include <iostream>
// #include <cstdio>
// #include <queue>
// #include <cstring>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// // void read(int &x) {
// // 	char ch = getchar(); x = 0;
// // 	for (; ch < '0' || ch > '9'; ch = getchar());
// // 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// // }
// const int INF = 60000;
// int cal;
// struct node
// {
// 	int x;
// 	int y;
// 	int step;
// 	int o2;
// 	node() {}
// 	node(int a, int b, int c, int d)
// 	{
// 		x = a;
// 		y = b;
// 		step = c;
// 		o2 = d;
// 	}
// 	bool operator <(node o)const
// 	{
// 		if (step != o.step)
// 			return step > o.step;
// 		else
// 			return o2 < o.o2;
// 	}
// };
// char ma[105][105];
// int vis[105][105];
// int dis[105][105];
// void bfs(node beg, int endx, int endy);
// int n, m;
// int main()
// {
// 	// std::ios::sync_with_stdio(false);
// // #ifdef test
// // 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// // #endif
// 	while (scanf("%d %d", &n, &m) != EOF)
// 	{
// 		if (n == 0 && m == 0)
// 			break;
// 		int i, j;
// 		memset(vis, -1, sizeof(vis));
// 		wfor(i, 0, n)
// 		{
// 			fill(dis[i], dis[i] + m + 1, INF);
// 		}
// 		int begx, begy, endx, endy;
// 		getchar();
// 		wfor(i, 0, n)
// 		{
// 			wfor(j, 0, m)
// 			{
// 				// cin >> ma[i][j];
// 				ma[i][j] = getchar();
// 			}
// 			getchar();
// 		}
// 		wfor(i, 0, n)
// 		{
// 			wfor(j, 0, m)
// 			{
// 				if (ma[i][j] == 'S')
// 				{
// 					begx = i;
// 					begy = j;
// 				} else if (ma[i][j] == 'T')
// 				{
// 					endx = i;
// 					endy = j;
// 				}
// 			}
// 		}
// 		bfs(node(begx, begy, 0, 0), endx, endy);
// 		if (dis[endx][endy] != INF)
// 			printf("%d\n", dis[endx][endy] );
// 		// cout << dis[endx][endy] << endl;
// 		else
// 			printf("%d\n", -1);
// 		// cout << -1 << endl;
// 		cout << cal << endl;
// 	}
// 	return 0;
// }
// void bfs(node beg, int endx, int endy)
// {
// 	priority_queue<node>qu;
// 	qu.push(beg);
// 	dis[beg.x][beg.y] = 0;
// 	while (!qu.empty())
// 	{
// 		cal++;
// 		const node temp = qu.top();
// 		qu.pop();
// 		if (temp.step >= dis[endx][endy])
// 			continue;
// 		vis[temp.x][temp.y] = temp.o2;
// 		int dx[4] = {0, 1, 0, -1};
// 		int dy[4] = {1, 0, -1, 0};
// 		int i;
// 		wfor(i, 0, 4)
// 		{
// 			int x = temp.x + dx[i];
// 			int y = temp.y + dy[i];
// 			if (x >= 0 && x < n && y >= 0 && y < m && ((vis[x][y] != 5 && ma[x][y] == 'B' && temp.o2 <= vis[x][y]) || (temp.o2 > vis[x][y])))
// 			{
// 				if (ma[x][y] == '.')
// 				{
// 					qu.push(node(x, y, temp.step + 1, temp.o2));
// 					dis[x][y] = min(temp.step + 1, dis[x][y]);
// 				} else if (ma[x][y] == '#')
// 				{
// 					if (temp.o2 >= 1)
// 					{
// 						qu.push(node(x, y, temp.step + 2, temp.o2 - 1));
// 						dis[x][y] = min(temp.step + 2, dis[x][y]);
// 					}
// 				} else if (ma[x][y] == 'B')
// 				{
// 					if (temp.o2 < 5)
// 						qu.push(node(x, y, temp.step + 1, temp.o2 + 1));
// 					else
// 						qu.push(node(x, y, temp.step + 1, temp.o2));
// 					dis[x][y] = min(dis[x][y], temp.step + 1);
// 				} else if (ma[x][y] == 'P')
// 				{
// 					qu.push(node(x, y, temp.step, temp.o2));
// 					if (temp.step < dis[x][y])
// 						dis[x][y] = temp.step;
// 				} else if (ma[x][y] == 'T')
// 				{
// 					dis[x][y] = min(dis[x][y], temp.step + 1);
// 					return;
// 				} else
// 				{
// 					qu.push(node(x, y, temp.step + 1, temp.o2));
// 					dis[x][y] = min(dis[x][y], temp.step + 1);
// 				}
// 			}
// 		}
// 	}
// }
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll INF = 150000;
struct node
{
	ll x;
	ll y;
	ll step;
	ll o2;
	node() {}
	node(ll a, ll b, ll c, ll d)
	{
		x = a;
		y = b;
		step = c;
		o2 = d;
	}
	bool operator <(node o)const
	{
		return step > o.step;
	}
};
char ma[105][105];
ll vis[105][105];
ll dis[105][105];
void bfs(node beg, ll endx, ll endy);
ll n, m;
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		ll i, j;
		memset(vis, -1, sizeof(vis));
		wfor(i, 0, n)
		{
			fill(dis[i], dis[i] + m + 1, INF);
		}
		ll begx, begy, endx, endy;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				cin >> ma[i][j];
			}
		}
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
		bfs(node(begx, begy, 0, 0), endx, endy);
		if (dis[endx][endy] != INF)
			cout << dis[endx][endy] << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
void bfs(node beg, ll endx, ll endy)
{
	priority_queue<node>qu;
	qu.push(beg);
	dis[beg.x][beg.y] = 0;
	while (!qu.empty())
	{
		const node temp = qu.top();
		qu.pop();
		if (temp.step >= dis[endx][endy])
			continue;
		vis[temp.x][temp.y] = temp.o2;
		ll dx[4] = {0, 1, 0, -1};
		ll dy[4] = {1, 0, -1, 0};
		ll i;
		wfor(i, 0, 4)
		{
			ll x = temp.x + dx[i];
			ll y = temp.y + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && ((temp.o2 != 0 && temp.o2 > vis[x][y]) || (temp.o2 == 0 && vis[x][y] == -1)))
			{
				if (ma[x][y] == '.')
				{
					qu.push(node(x, y, temp.step + 1, temp.o2));
					if (temp.step + 1 < dis[x][y])
					{
						dis[x][y] = temp.step + 1;
					}
				} else if (ma[x][y] == '#')
				{
					if (temp.o2 >= 1)
					{
						qu.push(node(x, y, temp.step + 2, temp.o2 - 1));
						if (temp.step + 2 < dis[x][y])
							dis[x][y] = temp.step + 2;
					}
				} else if (ma[x][y] == 'B')
				{
					ll tt = 1;
					ll cnt = 0;
					if (temp.o2 + cnt < 5)
					{
						ll j;
						ll flag = 2;
						ll flag2 = 1;
						ll can = 0;
						wfor(j, 0, 4)
						{
							ll tx = x + dx[j];
							ll ty = y + dy[j];
							if (tx >= 0 && tx < n && ty >= 0 && ty < m && ma[tx][ty] == 'B')
								flag2 = 2;
							if (tx >= 0 && tx < n && ty >= 0 && ty < m && ma[tx][ty] == 'P')
								flag = 1;
							if (tx >= 0 && tx < n && ty >= 0 && ty < m && ma[tx][ty] == '#')
							{
								can++;
							}
						}
						if (can == 4)
						{
							qu.push(node(x, y, temp.step + 1, temp.o2 + 1));
							if (temp.step + 1 < dis[x][y])
								dis[x][y] = temp.step + 1;
						}
						while (temp.o2 + cnt < 5 && can != 4)
						{
							cnt += flag2;
							qu.push(node(x, y, temp.step + tt, temp.o2 + cnt));
							if (temp.step + tt < dis[x][y])
								dis[x][y] = temp.step + tt;
							tt += flag;
						}
					} else
					{
						qu.push(node(x, y, temp.step + 1, temp.o2));
						if (temp.step + 1 < dis[x][y])
							dis[x][y] = temp.step + 1;
					}
				} else if (ma[x][y] == 'P')
				{
					qu.push(node(x, y, temp.step, temp.o2));
					if (temp.step < dis[x][y])
						dis[x][y] = temp.step;
				} else if (ma[x][y] == 'T')
				{
					if (temp.step + 1 < dis[x][y])
						dis[x][y] = temp.step + 1;
				} else
				{
					qu.push(node(x, y, temp.step + 1, temp.o2));
					if (temp.step + 1 < dis[x][y])
						dis[x][y] = temp.step + 1;
				}
			}
		}
	}
}