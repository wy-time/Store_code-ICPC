#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 205;
struct EDGE
{
	int _end;
	int w;
	int next;
};
int head[maxn];
EDGE edge [maxn * 100];
int cnt = -1;
void add(int beg, int _end, int w)
{
	edge[++cnt].next = head[beg];
	edge[cnt].w = w;
	edge[cnt]._end = _end;
	head[beg] = cnt;
}
int dfn[maxn];
int bfs(int beg, int _end)
{
	queue<int>qu;
	qu.push(beg);
	memset(dfn, -1, sizeof(dfn));
	dfn[beg] = 0;
	while (!qu.empty())
	{
		int i;
		int tem = qu.front();
		qu.pop();
		for (i = head[tem]; i != -1; i = edge[i].next)
		{
			int v = edge[i]._end;
			if (dfn[v] != -1 || edge[i].w <= 0)continue;
			dfn[v] = dfn[tem] + 1;
			qu.push(v);
		}
	}
	return dfn[_end];
}
int dfs(int beg, int _end, int flow)
{
	int i;
	int ans = 0;
	if (beg == _end)
	{
		return flow;
	}
	for (i = head[beg]; i != -1; i = edge[i].next)
	{
		int v = edge[i]._end;
		if (dfn[v] != dfn[beg] + 1 || edge[i].w <= 0)continue;
		int tmp = dfs(v, _end, min(flow - ans, edge[i].w));
		ans += tmp;
		edge[i].w -= tmp;
		edge[i ^ 1].w += tmp;
	}
	if (!ans)dfn[beg] = -1;
	return ans;
}
int dinic(int beg, int _end)
{
	int ans = 0;
	while (bfs(beg, _end) != -1)
	{
		ans += dfs(beg, _end, 0x7f7f7f7f);
	}
	return ans;
}
int main()
{
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(head, -1, sizeof(head));
		cnt = -1;
		int np, nc, m;
		// cin>>np>>nc>>m;
		scanf("%d%d%d", &np, &nc, &m);
		int i;
		wfor(i, 0, m)
		{
			// char tem;
			int u, v, w;
			scanf(" (%d,%d)%d", &u, &v, &w);
			// cin>>tem>>u>>tem>>v>>tem>>w;
			u++;
			v++;
			add(u, v, w);
			add(v, u, 0);
		}
		wfor(i, 0, np)
		{
			// char tmp;
			int id, w;
			// cin>>tmp>>id>>tmp>>w;
			scanf(" (%d)%d", &id, &w);
			id++;
			add(0, id, w);
			add(id, 0, 0);
		}
		wfor(i, 0, nc)
		{
			// char tem;
			int id, w;
			// cin>>tem>>id>>tem>>w;
			scanf(" (%d)%d", &id, &w);
			id++;
			add(id, 199, w);
			add(199, id, 0);
		}
		int ans = dinic(0, 199);
		cout << ans << endl;
	}
	return 0;
}
