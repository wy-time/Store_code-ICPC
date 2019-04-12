#include <iostream>
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
const int maxn = 2e5 + 5;
struct st
{
	int beg;
	int end;
	int next;
};
st edge[2 * maxn];
int head[maxn];
int vis[maxn];
int cnt;
void add(int u, int v)
{
	edge[++cnt].next = head[u];
	edge[cnt].end = v;
	edge[cnt].beg = u;
	head[u] = cnt;
}
int dfs(int now)
{
	int i;
	for (i = head[now]; i; i = edge[i].next)
	{
		int v = edge[i].end;
		if (vis[v] == 0)
		{
			vis[v] = vis[now] * -1;
			if (dfs(v) == 0)
				return 0;
		} else
		{
			if (vis[v] != vis[now] * -1)
				return 0;
		}
	}
	return 1;
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
	wfor(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	vis[1] = 1;
	if (dfs(1) == 1)
	{
		cout << "YES" << endl;
		wfor(i, 1, 2 * m + 1)
		{
			if (vis[edge[i].beg] == 1)
				cout << 1;
			else
				cout << 0;
			i++;
		}
	} else
		cout << "NO" << endl;
	return 0;
}
