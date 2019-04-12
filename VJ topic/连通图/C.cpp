#include <iostream>
#include <cstdio>
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
int head[maxn];
struct EDGE
{
	int _next;
	int _end;
};
EDGE edge[maxn * 4];
int cnt, deep, res;
void add(int beg, int _end)
{
	edge[++cnt]._next = head[beg];
	edge[cnt]._end = _end;
	head[beg] = cnt;
}
int dfn[maxn], low[maxn], father[maxn], bridge[maxn];
void tarjan(int beg, int fa);
void LCA(int beg, int _end);
int main()
{
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int n, m;
	int casecnt = 0;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		casecnt++;
		if (n == 0 && m == 0)
			break;
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(head, 0, sizeof(head));
		memset(father, 0, sizeof(father));
		memset(bridge, 0, sizeof(bridge));
		cnt = 0, deep = 0, res = 0;
		int i;
		wfor(i, 0, m)
		{
			int a, b;
			read(a); read(b);
			add(a, b);
			add(b, a);
		}
		tarjan(1, 0);
		int q;
		// cin >> q;
		read(q);
		// cout << "Case " << casecnt << ":" << endl;
		printf("Case %d:\n", casecnt);
		while (q--)
		{
			int a, b;
			read(a), read(b);
			LCA(a, b);
			// cout << res << endl;
			printf("%d\n", res);
		}
		// cout << endl;
		printf("\n");
	}
	return 0;
}
void tarjan(int beg, int fa)
{
	int i;
	dfn[beg] = low[beg] = ++deep;
	for (i = head[beg]; i != 0; i = edge[i]._next)
	{
		if (edge[i]._end == fa)
			continue;
		if (!dfn[edge[i]._end])
		{
			father[edge[i]._end] = beg;
			tarjan(edge[i]._end, beg);
			low[beg] = min(low[edge[i]._end], low[beg]);
			if (dfn[beg] < low[edge[i]._end])
			{
				res++;
				bridge[edge[i]._end] = 1;
			}
		} else
			low[beg] = min(low[beg], dfn[edge[i]._end]);
	}
}
void LCA(int beg, int _end)
{
	while (dfn[beg] < dfn[_end])
	{
		if (bridge[_end])
		{
			res--;
			bridge[_end] = 0;
		}
		_end = father[_end];
	}
	while (dfn[_end] < dfn[beg])
	{
		if (bridge[beg])
		{
			res--;
			bridge[beg] = 0;
		}
		beg = father[beg];
	}
	while (beg != _end)
	{
		if (bridge[beg])
		{
			res--;
			bridge[beg] = 0;
		}
		if (bridge[_end])
		{
			res--;
			bridge[_end] = 0;
		}
		beg = father[beg];
		_end = father[_end];
	}
}