#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const int maxn = 100005;
int step[maxn];
struct EDGE
{
	int _end;
	int _next;
};
EDGE edge[maxn * 2 + 105];
int head[maxn];
int cnt;
int vis[maxn];
void bfs(int beg, int _end);
void add(int beg, int _end)
{
	edge[++cnt]._next = head[beg];
	edge[cnt]._end = _end;
	head[beg] = cnt;
}
int main()
{
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int n, m;
	// cin >> n >> m;
	read(n); read(m);
	int i;
	cnt = 0;
	wfor(i, 0, m)
	{
		int a, b;
		// cin >> a >> b;
		read(a); read(b);
		add(a, b);
		add(b, a);
	}
	int q;
	cin >> q;
	while (q--)
	{
		memset(vis, 0, sizeof(int) * (n + 1));
		int a, b;
		// cin >> a >> b;
		read(a); read(b);
		bfs(a, b);
		// cout << step[b] << endl;
		printf("%d\n", step[b]);
	}
	return 0;
}
void bfs(int beg, int _end)
{
	queue<int>qu;
	qu.push(beg);
	step[beg] = 0;
	while (!qu.empty())
	{
		int x = qu.front();
		qu.pop();
		int i;
		for (i = head[x]; i != 0; i = edge[i]._next)
		{
			if (!vis[edge[i]._end])
			{
				step[edge[i]._end] = step[x] + 1;
				qu.push(edge[i]._end);
				vis[edge[i]._end] = 1;
			}
			if (edge[i]._end == _end)
				return ;
		}
	}
}