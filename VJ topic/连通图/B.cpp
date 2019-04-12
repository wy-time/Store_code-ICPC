#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
struct EDGE
{
	ll _next;
	ll _end;
};
ll ans;
void add(ll beg, ll _end);
EDGE edge[1005];
ll head[105];
ll dfn[105], low[105], vis[105], father[105];
ll cnt, deep;
void tarjan(ll beg, ll fa);
int main()
{
	ll n;
	while (scanf("%lld", &n))
	{
		if (n == 0)
			break;
		cnt = 0, deep = 0, ans = 0;
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(vis, 0, sizeof(vis));
		memset(father, 0, sizeof(father));
		memset(head, 0, sizeof(head));
		ll g = 1;
		while (scanf("%lld", &g) && g)
		{
			char x; ll a;
			while (scanf("%lld%c", &a, &x))
			{
				add(g, a);
				add(a, g);
				if (x == '\n')
					break;
			}
		}
		tarjan(1, 0);
		printf("%lld\n", ans);
	}
	return 0;
}
void add(ll beg, ll _end)
{
	edge[++cnt]._next = head[beg];
	edge[cnt]._end = _end;
	head[beg] = cnt;
}
void tarjan (ll beg, ll fa)
{
	int children = 0;
	dfn[beg] = low[beg] = ++deep;
	ll i;
	father[beg] = fa;
	for (i = head[beg]; i != 0; i = edge[i]._next)
	{
		if (!dfn[edge[i]._end])
		{
			children++;
			tarjan(edge[i]._end, beg);
			low[beg] = min(low[beg], low[edge[i]._end]);
			if (father[beg] == 0 && children >= 2)
			{
				if (!vis[beg])
				{
					ans++;
					vis[beg] = 1;
				}
			}
			else if (father[beg] != 0 && low[edge[i]._end] >= dfn[beg])
			{
				if (!vis[beg])
				{
					ans++;
					vis[beg] = 1;
				}
			}
		} else
		{
			if (fa != edge[i]._end)
				low[beg] = min(low[beg], dfn[edge[i]._end]);
		}
	}
}