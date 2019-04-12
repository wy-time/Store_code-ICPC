#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 3005;
const int INF = 0x7f7f7f7f;
struct EDGE
{
	int first;
	int flow;
	int cost;
	int _end;
	int next;
};
int head[maxn];
EDGE edge[2 * maxn];
int cnt = -1;
void add(int beg, int _end, int flow, int cost)
{
	edge[++cnt].next = head[beg];
	edge[cnt]._end = _end;
	edge[cnt].flow = flow;
	edge[cnt].cost = cost;
	edge[cnt].first = beg;
	head[beg] = cnt;
}
int shop[100][100];
int supply[100][100];
int vis[maxn];
int dis[maxn];
int pre[maxn];
int sum = 0;
int spfa(int beg, int _end)
{
	queue<int>qu;
	memset(vis, 0, sizeof(vis));
	fill(dis, dis + maxn, INF);
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
			if (edge[i].flow <= 0) continue;
			if (edge[i].cost + dis[temp] < dis[v])
			{
				dis[v] = edge[i].cost + dis[temp];
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
	return 1;
}
int mfmc(int beg, int _end)
{
	int ans = 0;
	memset(pre, -1, sizeof(pre));
	while (spfa(beg, _end) == 1)
	{
		int t = pre[_end];
		int flow = INF;
		while (t != -1)
		{
			flow = min(edge[t].flow, flow);
			t = pre[edge[t].first];
		}
		t = pre[_end];
		while (t != -1)
		{
			edge[t].flow -= flow;
			edge[t ^ 1].flow += flow;
			ans += flow * edge[t].cost;
			t = pre[edge[t].first];
		}
		sum += flow;
	}
	return ans;
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
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		if (n == 0 && m == 0 && k == 0)
			break;
		int i, j;
		int need = 0;
		sum = 0;
		wfor(i, 0, n)
		{
			wfor(j, 0, k)
			{
				cin >> shop[i][j];
				need += shop[i][j];
			}
		}
		wfor(i, 0, m)
		{
			wfor(j, 0, k)
			{
				cin >> supply[i][j];
			}
		}
		int res = 0;
		wfor(i, 0, k)
		{
			cnt = -1;
			memset(head, -1, sizeof(head));
			wfor(j, 0, n)
			{
				add(100 + j, 300, shop[j][i], 0);
				add(300, 100 + j, 0, 0);
			}
			wfor(j, 0, m)
			{
				add(0, j + 1, supply[j][i], 0);
				add(j + 1, 0, 0, 0);
			}
			wfor(j, 0, n)
			{
				int l;
				wfor(l, 0, m)
				{
					int t;
					cin >> t;
					add(l + 1, 100 + j, INF, t);
					add(100 + j, l + 1, 0, -t);
				}
			}
			res += mfmc(0, 300);
		}
		if (need <= sum)
			cout << res << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
