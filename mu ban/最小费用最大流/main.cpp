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
const int INF = 0x7f7f7f7f;
struct EDGE
{
	int first;
	int _end;
	int cost;
	int w;
	int next;
};
EDGE edge [100005];
int head[5005];
int pre[5005];
int dis[5005];
int vis[5005];
int cnt = -1;
inline void add(int beg, int _end, int w, int cost)
{
	edge[++cnt].next = head[beg];
	edge[cnt].w = w;
	edge[cnt].cost = cost;
	edge[cnt].first = beg;
	edge[cnt]._end = _end;
	head[beg] = cnt;
}
inline int spfa(int beg, int _end)
{
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	fill(dis, dis + 5005, INF);
	queue<int>qu;
	qu.push(beg);
	vis[beg] = 1;
	dis[beg] = 0;
	while (!qu.empty())
	{
		int temp = qu.front();
		qu.pop();
		vis[temp] = 0;
		for (int i = head[temp]; i != -1; i = edge[i].next)
		{
			int v = edge[i]._end;
			if (edge[i].w > 0 && dis[v] > dis[temp] + edge[i].cost)
			{
				dis[v] = dis[temp] + edge[i].cost;
				pre[v] = i;
				if (!vis[v])
				{
					qu.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	if (dis[_end] == INF)
		return 0;
	else
		return 1;
}
inline void min_cost(int beg, int _end)
{
	int flow = 0;
	int cost = 0;
	while (spfa(beg, _end))
	{
		int t = _end;
		int w = INF;
		while (pre[t] != -1)
		{
			w = min(w, edge[pre[t]].w);
			t = edge[pre[t]].first;
		}
		flow += w;
		cost += w * dis[_end];
		t = _end;
		while (pre[t] != -1)
		{
			edge[pre[t]].w -= w;
			edge[pre[t] ^ 1].w += w;
			t = edge[pre[t]].first;
		}
	}
	// cout << flow << " " << cost << endl;
	printf("%d %d\n", flow, cost);
}
int main()
{
	// std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int n, m, s, t;
	// cin >> n >> m >> s >> t;
	read(n), read(m), read(s), read(t);
	memset(head, -1, sizeof(head));
	int i;
	wfor(i, 0, m)
	{
		int u, v, w, c;
		// cin >> u >> v >> w >> c;
		read(u), read(v), read(w), read(c);
		add(u, v, w, c);
		add(v, u, 0, -c);
	}
	min_cost(s, t);
	return 0;
}
