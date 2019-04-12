#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int bfs();
typedef map<int, int>map1;
map1 ma;
int n, m;
int vis[300];
struct st
{
	int x;
	int step;
	st() {}
	st(int a, int b)
	{
		x = a;
		step = b;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	cin >> n >> m;
	int i;
	wfor(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		ma.insert(make_pair(a, b));
	}
	int res = bfs();
	cout << res << endl;
	return 0;
}
int bfs()
{
	queue<st>qu;
	qu.push(st(0, 0));
	int dx[2] = {1, -1};
	int i;
	while (!qu.empty())
	{
		st now = qu.front();
		qu.pop();
		wfor(i, 0, 2)
		{
			vis[now.x] = 1;
			int x = now.x + dx[i];
			if (ma.count(now.x) != 0)
			{
				int t = ma[now.x];
				if (t >= 0 && t <= n && !vis[t])
				{
					qu.push(st(t, now.step + 1));
				}
			}
			if (x == n)
				return now.step + 1;
			if (x >= 0 && x <= n && !vis[x])
			{
				qu.push(st(x, now.step + 1));
			}
			if (ma.count(x) != 0)
			{
				x = ma[x];
				if (x >= 0 && x <= n && !vis[x])
				{
					qu.push(st(x, now.step + 2));
				}
			}
		}
	}
	return -1;
}