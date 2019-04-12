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
const ll maxn = 1e5 + 5;
struct EDGE
{
	ll to;
	ll w;
	ll next;
};
struct node
{
	ll id;
	ll dis;
	node (ll a, ll b)
	{
		id = a;
		dis = b;
	}
	bool operator <(const node a)const
	{
		return dis > a.dis;
	}
};
struct st
{
	ll id;
	ll f;
	ll h;
	st (ll a, ll b, ll c)
	{
		id = a;
		f = b;
		h = c;
	}
	bool operator<(const st a)const
	{
		if (a.f == f)
			return a.h < h;
		else
			return a.f < f;
	}
};
ll head[1005];
ll rhead[1005];
EDGE edge[maxn];
EDGE redge[maxn];
int vis[1005];
void add(ll beg, ll to, ll w, ll &cnt);
void dij(ll beg);
ll A_star(ll s, ll e, ll k);
ll dis[1005];
const ll INF = 0x7f7f7f7f;
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	ll n, m;
	while (cin >> n >> m)
	{
		ll i;
		ll cnt = 0;
		wfor(i, 0, m)
		{
			ll a, b, c;
			cin >> a >> b >> c;
			add(a, b, c, cnt);
		}
		ll s, e, k;
		fill(dis + 1, dis + n + 1, INF);
		memset(vis, 0, sizeof(vis));
		cin >> s >> e >> k;
		dij(e);
		ll res = A_star(s, e, k);
		cout << res << endl;
	}
	return 0;
}
void add(ll beg, ll to, ll w, ll &cnt)
{
	edge[++cnt].next = head[beg];
	redge[cnt].next = rhead[to];
	edge[cnt].w = w;
	redge[cnt].w = w;
	edge[cnt].to = to;
	redge[cnt].to = beg;
	head[beg] = cnt;
	rhead[to] = cnt;
}
void dij(ll beg)
{
	priority_queue<node>qu;
	qu.push(node(beg, 0));
	dis[beg] = 0;
	while (!qu.empty())
	{
		node temp = qu.top();
		qu.pop();
		ll i;
		if (vis[temp.id])
			continue;
		else
			vis[temp.id] = 1;
		for (i = rhead[temp.id]; i != 0; i = redge[i].next)
		{
			if (dis[temp.id] + redge[i].w < dis[redge[i].to])
			{
				dis[redge[i].to] = dis[temp.id] + redge[i].w;
				qu.push(node(redge[i].to, dis[redge[i].to]));
			}
		}
	}
}
ll A_star(ll s,  ll e, ll k)
{
	priority_queue<st>qu;
	qu.push(st(s, dis[s], 0));
	ll cnt = 0;
	if (s == e)
		k++;
	if (dis[s] == INF)
		return -1;
	// if (s == e)
	// 	cnt++;
	while (!qu.empty())
	{
		st temp = qu.top();
		qu.pop();
		ll i;
		if (dis[temp.id] == INF)
			continue;
		for (i = head[temp.id]; i != 0; i = edge[i].next)
		{
			qu.push(st(edge[i].to, dis[edge[i].to] + temp.h + edge[i].w, temp.h + edge[i].w));
		}
		if (temp.id == e)
		{
			cnt++;
		}
		if (cnt == k)
			return temp.f;
	}
	return -1;
}

// #include <iostream>
// #include <cstring>
// #include <cstdlib>
// #include <cstdio>
// #include <queue>
// #define MAXN 1005
// #define MAXM 500005
// #define INF 1000000000
// using namespace std;
// struct node
// {
// 	int v, w, next;
// } edge[MAXM], revedge[MAXM];
// struct A
// {
// 	int f, g, v;
// 	bool operator <(const A a)const {
// 		if (a.f == f) return a.g < g;
// 		return a.f < f;
// 	}
// };
// int e, vis[MAXN], d[MAXN], q[MAXM * 5];
// int head[MAXN], revhead[MAXN];
// int n, m, s, t, k;
// void init()
// {
// 	e = 0;
// 	memset(head, -1, sizeof(head));
// 	memset(revhead, -1, sizeof(revhead));
// }
// void insert(int x, int y, int w)
// {
// 	edge[e].v = y;
// 	edge[e].w = w;
// 	edge[e].next = head[x];
// 	head[x] = e;
// 	revedge[e].v = x;
// 	revedge[e].w = w;
// 	revedge[e].next = revhead[y];
// 	revhead[y] = e++;
// }
// void spfa(int src)
// {
// 	for (int i = 1; i <= n; i++) d[i] = INF;
// 	memset(vis, 0, sizeof(vis));
// 	vis[src] = 0;
// 	int h = 0, t = 1;
// 	q[0] = src;
// 	d[src] = 0;
// 	while (h < t)
// 	{
// 		int u = q[h++];
// 		vis[u] = 0;
// 		for (int i = revhead[u] ; i != -1; i = revedge[i].next)
// 		{
// 			int v = revedge[i].v;
// 			int w = revedge[i].w;
// 			if (d[v] > d[u] + w)
// 			{
// 				d[v] = d[u] + w;
// 				if (!vis[v])
// 				{
// 					q[t++] = v;
// 					vis[v] = 1;
// 				}
// 			}
// 		}
// 	}
// }
// int Astar(int src, int des)
// {
// 	int cnt = 0;
// 	priority_queue<A>Q;
// 	if (src == des) k++;
// 	if (d[src] == INF) return -1;
// 	A t, tt;
// 	t.v = src, t.g = 0, t.f = t.g + d[src];
// 	Q.push(t);
// 	while (!Q.empty())
// 	{
// 		tt = Q.top();
// 		Q.pop();
// 		if (tt.v == des)
// 		{
// 			cnt++;
// 			if (cnt == k) return tt.g;
// 		}
// 		for (int i = head[tt.v]; i != -1; i = edge[i].next)
// 		{
// 			t.v = edge[i].v;
// 			t.g = tt.g + edge[i].w;
// 			t.f = t.g + d[t.v];
// 			Q.push(t);
// 		}
// 	}
// 	return -1;
// }
// int main()
// {
// 	int x, y, w;
// 	while (scanf("%d%d", &n, &m) != EOF)
// 	{
// 		init();
// 		for (int i = 1; i <= m; i++)
// 		{
// 			scanf("%d%d%d", &x, &y, &w);
// 			insert(x, y, w);
// 		}
// 		scanf("%d%d%d", &s, &t, &k);
// 		spfa(t);
// 		printf("%d\n", Astar(s, t));
// 	}
// 	return 0;
// }
