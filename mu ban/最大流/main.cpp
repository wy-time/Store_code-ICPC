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
const int maxn = 2e5 + 5;
struct EDGE
{
	int first;
	int _end;
	int w;
	int next;
};
EDGE edge[maxn];
int head[maxn / 2];
int vis[maxn];
int pre[maxn];
int cnt = -1;
void add(int beg, int _end, int w)
{
	edge[++cnt].next = head[beg];
	edge[cnt].first = beg;
	edge[cnt].w = w;
	edge[cnt]._end = _end;
	head[beg] = cnt;
}
int bfs(int beg, int _end)
{
	queue<int>qu;
	qu.push(beg);
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	vis[beg] = 1;
	while (!qu.empty())
	{
		int temp = qu.front();
		qu.pop();
		for (int i = head[temp]; i != -1; i = edge[i].next)
		{
			int v = edge[i]._end;
			if (edge[i].w <= 0 || vis[v])
				continue;
			pre[v] = i;
			vis[v] = 1;
			if (v == _end)
				return 1;
			qu.push(v);
		}
	}
	return 0;
}
int EK(int beg, int _end)
{
	int ans = 0;
	while (bfs(beg, _end))
	{
		int temp = pre[_end];
		int reduse = 0x7f7f7f7f;
		while (temp != -1)
		{
			reduse = min(reduse, edge[temp].w);
			temp = pre[edge[temp].first];
		}
		temp = pre[_end];
		while (temp != -1)
		{
			edge[temp].w -= reduse;
			edge[temp ^ 1].w += reduse;
			temp = pre[edge[temp].first];
		}
		ans += reduse;
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m, s, t;
	int i;
	memset(head, -1, sizeof(head));
	wfor(i, 0, m)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, 0);
	}
	cout << EK(s, t) << endl;
	return 0;
}
