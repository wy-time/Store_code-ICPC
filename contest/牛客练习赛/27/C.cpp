#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn = 50005;
struct EDGE
{
	ll w;
	ll _next;
	ll _end;
};
EDGE edge[maxn];
ll head[maxn];
void add(ll beg, ll _end, ll w);
ll cnt;
ll vis[maxn];
void dfs(ll beg, ll sum);
ll _max;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll n, x;
	cin >> n >> x;
	ll i;
	cnt = 0;
	ll sum = 0;
	wfor(i, 0, n - 1)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		sum += c;
		add(a, b, c);
		add(b, a, c);
	}
	vis[x] = 1;
	dfs(x, 0);
	sum -= _max;
	cout << sum * 2 + _max << endl;
	return 0;
}
void add(ll beg, ll _end, ll w)
{
	edge[++cnt]._next = head[beg];
	edge[cnt]._end = _end;
	edge[cnt].w = w;
	head[beg] = cnt;
}
void dfs(ll beg, ll sum)
{
	int i;
	_max = max(sum, _max);
	for (i = head[beg]; i != 0; i = edge[i]._next)
	{
		if (!vis[edge[i]._end])
		{
			vis[edge[i]._end] = 1;
			sum += edge[i].w;
			dfs(edge[i]._end, sum);
			sum -= edge[i].w;
			vis[edge[i]._end] = 0;
		}
	}
}