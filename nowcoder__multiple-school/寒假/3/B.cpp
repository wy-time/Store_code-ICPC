#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(ll &x) {
	ll flag = 0;
	char ch = getchar(); x = 0;
	if (ch == '-')
		flag = 1;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	if (flag)
		x *= -1;
}
const ll maxn = 1e5 + 5;
const ll INF = 0x7f7f7f7f7f7f7f;
struct EDGE
{
	ll _end;
	ll w1;
	ll w2;
	ll next;
};
// struct DIS
// {
// 	ll id;
// 	ll dis;
// 	DIS() {}
// 	DIS(ll a, ll b)
// 	{
// 		id = a;
// 		dis = b;
// 	}
// };
// struct rule
// {
// 	bool operator()(const DIS &a, const DIS &b)
// 	{
// 		return a.dis < b.dis;
// 	}
// };
ll head[maxn];
EDGE edge [2 * maxn];
ll cnt, scnt;
ll dis[maxn];
// ll vis[maxn];
ll indeg[maxn];
ll shead[maxn];
void add(ll beg, ll _end, ll w1, ll w2)
{
	edge[++cnt].next = head[beg];
	edge[cnt]._end = _end;
	edge[cnt].w1 = w1;
	edge[cnt].w2 = w2;
	head[beg] = cnt;
}
void toop(ll n)
{
	queue<ll>qu;
	ll i;
	wfor(i, 1, n + 1)
	{
		if (indeg[i] == 0)
			qu.push(i);
	}
	while (!qu.empty())
	{
		ll u = qu.front();
		qu.pop();
		shead[scnt++] = u;
		ll i;
		for (i = head[u]; i; i = edge[i].next)
		{
			ll v = edge[i]._end;
			indeg[v]--;
			if (indeg[v] == 0)
				qu.push(v);
		}
	}
}
void dij1(ll beg)
{
	dis[beg] = 0;
	ll i;
	wfor(i, 0, scnt)
	{
		ll j;
		ll u = shead[i];
		for (j = head[u]; j; j = edge[j].next)
		{
			ll v = edge[j]._end;
			if (dis[v] > dis[u] + edge[j].w1)
			{
				dis[v] = dis[u] + edge[j].w1;
			}
		}
	}
}
void dij2(ll beg)
{
	dis[beg] = 0;
	ll i;
	wfor(i, 0, scnt)
	{
		ll j;
		ll u = shead[i];
		for (j = head[u]; j; j = edge[j].next)
		{
			ll v = edge[j]._end;
			if (dis[v] > dis[u] + edge[j].w2)
			{
				dis[v] = dis[u] + edge[j].w2;
			}
		}
	}
}
int main()
{
	// std::ios::sync_with_stdio(false);
	// #ifdef test
	// freopen("F:\\Desktop\\question\\in.txt","r",stdin);
	// #endif
	// #ifdef ubuntu
	// freopen("/home/time/debug/debug/in","r",stdin);
	// freopen("/home/time/debug/debug/out","w",stdout);
	// #endif
	ll t;
	// cin>>t;
	read(t);
	while (t--)
	{
		cnt = 0;
		scnt = 0;
		memset(head, 0, sizeof(head));
		ll n, m;
		// cin>>n>>m;
		memset(indeg, 0, sizeof(indeg));
		read(n), read(m);
		ll i;
		wfor(i, 0, m)
		{
			ll u, v, w, w1, w2;
			// cin>>u>>v>>
			read(u), read(v), read(w), read(w1), read(w2);
			indeg[v]++;
			add(u, v, w - w1, w - w2);
		}
		toop(n);
		fill(dis, dis + maxn, INF);
		dij1(1);
		ll cnz = dis[n];
		fill(dis, dis + maxn, INF);
		dij2(1);
		ll lj = dis[n];
		if (lj < 0)
			lj = 0;
		if (cnz < 0)
		{
			if (lj != 0)
			{
				printf("cnznb!!!\n" );
				printf("%lld\n", lj);

			} else
				printf("oof!!!\n" );
		} else
		{
			if (cnz > lj)
			{
				printf("rip!!!\n");
				printf("%lld\n", cnz - lj );
				// cout << "rip!!!" << endl;
				// cout << cnz - lj << endl;
			} else if (cnz == lj)
			{
				printf("oof!!!\n" );
				// cout << "oof!!!" << endl;
			} else
			{
				printf("cnznb!!!\n" );
				printf("%lld\n", lj - cnz );
				// cout << "cnznb!!!" << endl;
				// cout << lj - cnz << endl;
			}
		}
	}
	return 0;
}
