#include <iostream>
// #ifdef test
// #include <cstdio>
// #endif
#include <cstring>
#include <cstdio>
#include <queue>
// #include <cstdlib>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
struct EDGE
{
	ll the_end;
	ll w;
	ll next;
	ll id;
};
EDGE edge[400005];
int head[100005];
int vis[100005];
ll dis[100005];
int cnt;
int id[100005];
const ll inf = 0x7f7f7f7f;
inline void add(ll beg, ll the_end, ll w, ll id);
inline void dijkstra(ll s, ll n);
inline void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
struct node
{
	ll d, u;
};
struct rule
{
	bool operator()(const node &a, const node &b)
	{
		return a.d > b.d;
	}
};
int main()
{
	//std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("in", "r", stdin);
// #endif
	ll n, m;
	// system("pause");
	while (scanf("%lld %lld", &n, &m) != EOF)
	{
		// memset(vis, 0, sizeof(vis));
		// memset(id, -1, sizeof(id));
		memset(head, 0, sizeof(head));
		dis[1] = 0;
		cnt = 0;
		id[1] = -1;
		register int i;
		int a, b, c;
		wfor(i, 0, m)
		{
			read(a); read(b); read(c);
			// scanf("%lld %lld %lld", &a, &b, &c);
			add(a, b, 0, c);
			add(b, a, 0, c);
		}
		dijkstra(1, n);
		if (dis[n] == inf)
			printf("-1\n");
		else
			printf("%lld\n", dis[n] + 1);
	}
	return 0;
}
inline void add(ll beg, ll the_end, ll w, ll id)
{
	edge[++cnt].next = head[beg];
	edge[cnt].w = w;
	edge[cnt].the_end = the_end;
	edge[cnt].id = id;
	head[beg] = cnt;
}
inline void dijkstra(ll s, ll n)
{
	register int i;
	register ll last_id = -1;
	wfor(i, 1, n + 1)
	{
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[s] = 0;
	priority_queue<node, vector<node>, rule> qu;
	qu.push((node) {0, s});
	while (!qu.empty())
	{
		node x = qu.top();
		qu.pop();
		register int u = x.u;
		if (vis[u]) continue;
		else {}
		vis[u] = 1;
		last_id = id[u];
		for (i = head[u]; i != 0; i = edge[i].next)
		{
			ll fix = 0;
			if (edge[i].id != last_id && last_id != -1)
			{
				fix = 1;
			} else
			{
			}
			if (!vis[edge[i].the_end] && edge[i].w + dis[u] + fix < dis[edge[i].the_end])
			{
				dis[edge[i].the_end] = edge[i].w + dis[u] + fix;
				id[edge[i].the_end] = edge[i].id;
				qu.push((node) {dis[edge[i].the_end], edge[i].the_end});
			} else
			{}
		}
	}
	// for (j = 1; j <= n; j++)
	// {
	// 	vis[s] = 1;
	// 	for (i = head[s]; i != 0; i = edge[i].next)
	// 	{
	// 		ll fix = 0;
	// 		if (edge[i].id != last_id && last_id != -1)
	// 		{
	// 			fix = 1;
	// 		}
	// 		if (!vis[edge[i].the_end] && edge[i].w + dis[s] + fix < dis[edge[i].the_end])
	// 		{
	// 			dis[edge[i].the_end] = edge[i].w + dis[s] + fix;
	// 			id[edge[i].the_end] = edge[i].id;
	// 		}
	// 	}
	// 	ll temp = inf;
	// 	for (i = 1; i <= n; i++)
	// 	{
	// 		if (!vis[i] && temp > dis[i])
	// 		{
	// 			s = i;
	// 			last_id = id[i];
	// 			temp = dis[i];
	// 		}
	// 	}
	// }
}
