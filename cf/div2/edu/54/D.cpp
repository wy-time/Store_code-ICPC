#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 3e5 + 5;
const ll INF = 1e18 + 5;
struct EDGE
{
	ll first;
	ll _end;
	ll w;
	ll next;
	ll id;
};
struct DIS
{
	ll poll;
	ll dis;
	DIS() {}
	DIS(ll a, ll b)
	{
		poll = a;
		dis = b;
	}
	bool operator < (const DIS b) const
	{
		if (this->dis != b.dis)
			return this->dis < b.dis;
		else
			return this->poll < b.poll;
	}
};
EDGE edge[2 * (maxn + 1)];
ll head[maxn + 1];
ll pre[maxn + 1];
ll dis[maxn + 1];
ll cnt = 0;
vector<ll> ans;
void add(ll beg, ll _end, ll w, ll id)
{
	edge[++cnt].next = head[beg];
	edge[cnt].w = w;
	edge[cnt].first = beg;
	edge[cnt]._end = _end;
	edge[cnt].id = id;
	head[beg] = cnt;
}
void dij(ll beg, ll k)
{
	set<DIS>qu;
	dis[beg] = 0;
	qu.insert(DIS(beg, 0));
	ll num = 0;
	while (!qu.empty() && num < k)
	{
		ll temp = qu.begin()->poll;
		qu.erase(DIS(temp, dis[temp]));
		if (pre[temp] != 0)
		{
			num++;
			ans.push_back(pre[temp]);
		}
		ll i;
		for (i = head[temp]; i != 0; i = edge[i].next)
		{
			ll v = edge[i]._end;
			if (dis[v] > dis[temp] + edge[i].w)
			{
				qu.erase(DIS(v, dis[v]));
				pre[v] = edge[i].id;
				dis[v] = dis[temp] + edge[i].w;
				qu.insert(DIS(v, dis[v]));
			}
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll n, m, k;
	cin >> n >> m >> k;
	ll i;
	wfor(i, 0, m)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		add(u, v, w, i + 1);
		add(v, u, w, i + 1);
	}
	fill(dis, dis + maxn + 1, INF);
	memset(pre, 0, sizeof(pre));
	dij(1, k);
	cout << ans.size() << endl;
	for (auto it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
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
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif

	return 0;
}
