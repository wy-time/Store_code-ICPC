#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
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
const int maxn = 200005;
int num[maxn];
//int num2[maxn];
int val[maxn];
struct EDGE
{
	int end;
	int _next;
};
EDGE edge[maxn * 2];
int head[maxn];
int cnt = 0;
int st[20 * maxn][20];
int pos[20 * maxn][20];
void add(int beg, int end)
{
	edge[++cnt]._next = head[beg];
	edge[cnt].end = end;
	head[beg] = cnt;
}
vector<int>dfn;
int first_pos[maxn];
int vis[maxn];
vector<int>point;
int root[maxn];
int fa[maxn];
struct node
{
	int lch;
	int rch;
	int cnt;
};
node tree[maxn * 40];
int tree_cnt;
void build_new(int l, int r, int old, int &now, int number)
{
	tree[++tree_cnt] = tree[old];
	tree[tree_cnt].cnt++;
	now = tree_cnt;
	if (l == r)return ;
	int mid = (l + r) >> 1;
	if (mid >= number)
		build_new(l, mid, tree[old].lch, tree[now].lch, number);
	else
		build_new(mid + 1, r, tree[old].rch, tree[now].rch, number);
}
int cal_lca(int a, int b)
{
	int l = first_pos[a];
	int r = first_pos[b];
	if (l > r)swap(l, r);
	int len = r - l + 1;
	len = log2(len);
	if (st[l][len] < st[(r - (1 << len) + 1)][len])
	{
		return point[pos[l][len]];
	} else
		return point[pos[r - (1 << len) + 1][len]];
}
int query(int l, int r, int root1, int root2, int lca, int lca_fa, int k)
{
	if (l == r)
		return l;
	int temp = tree[tree[root1].lch].cnt + tree[tree[root2].lch].cnt - tree[tree[lca].lch].cnt - tree[tree[lca_fa].lch].cnt;
	int mid = (l + r) >> 1;
	if (temp >= k)
		return query(l, mid, tree[root1].lch, tree[root2].lch, tree[lca].lch, tree[lca_fa].lch, k);
	else
		return query(mid + 1, r, tree[root1].rch, tree[root2].rch, tree[lca].rch, tree[lca_fa].rch, k - temp);
}
void dfs(int now, int dep, int father, int n)
{
	int i;
	dfn.push_back(dep);
	point.push_back(now);
	build_new(1, n, root[father], root[now], val[now]);
	fa[now] = father;
	if (vis[now] == 0)
		first_pos[now] = dfn.size() - 1;
	vis[now] = 1;
	for (i = head[now]; i; i = edge[i]._next)
	{
		int v = edge[i].end;
		if (!vis[v])
		{
			dfs(v, dep + 1, now, n);
			dfn.push_back(dep);
			point.push_back(now);
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	int i;
	wfor(i, 1, n + 1)
	{
		cin >> num[i];
		val[i] = num[i];
		//num2[i]=num[i];
	}
	sort(num + 1, num + n + 1);
	int leng = unique(num + 1, num + n + 1) - num - 1;
	wfor(i, 1, n + 1)
	val[i] = lower_bound(num + 1, num + leng + 1, val[i]) - num;
	wfor(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	dfs(1, 1, 0, leng);
	int len = dfn.size();
	wfor(i, 0, len)
	{
		st[i][0] = dfn[i];
		pos[i][0] = i;
	}
	int j;
	int en = log2(len) + 2;
	wfor(j, 1, en)
	{
		wfor(i, 0, len)
		{
			st[i][j] = min(st[i][j - 1], st[(i + (1 << (j - 1)))][j - 1]);
			if (st[i][j - 1] < st[(i + (1 << (j - 1)))][j - 1])
				pos[i][j] = pos[i][j - 1];
			else
				pos[i][j] = pos[i + ((1 << (j - 1)))][j - 1];
		}
	}
	int lastans = 0;
	wfor(i, 0, m)
	{
		int u, v, k;
		cin >> u >> v >> k;
		u = u ^ lastans;
		int lca = cal_lca(u, v);
		int ans = query(1, leng, root[u], root[v], root[lca], root[fa[lca]], k);
		ans = num[ans];
		cout << ans << endl;
		lastans = ans;
	}
	return 0;
}
