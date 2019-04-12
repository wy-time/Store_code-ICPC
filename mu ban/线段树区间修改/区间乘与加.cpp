#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const ll maxn = 1e5 + 6;
ll num[maxn];
ll node[maxn << 2];
ll add[maxn << 2];
ll mul[maxn << 2];
void build(ll l, ll r, ll id);
void push_up(ll id);
void up_data(ll L, ll R, ll l, ll r, ll id, ll op, ll x);
void push_down(ll lt, ll rl, ll id);
ll query(ll L, ll R, ll l, ll r, ll id);
ll p;
int main()
{
	//std::ios::sync_with_stdio(false);
	ll n, m;
	scanf("%lld%lld%lld", &n, &m, &p);
	// cin >> n >> m >> p;
	ll i;
	fill(mul + 1, mul + maxn * 4, 1);
	wfor(i, 1, n + 1)
	{
		// cin >> num[i];
		scanf("%lld", &num[i]);
	}
	build(1, n, 1);
	wfor(i, 0, m)
	{
		ll op, x, y;
		// cin >> op >> x >> y;
		scanf("%lld%lld%lld", &op, &x, &y);
		if (op == 1)
		{
			ll k;
			// cin >> k;
			scanf("%lld", &k);
			up_data(x, y, 1, n, 1, 1, k % p);
		} else if (op == 2)
		{
			ll k;
			// cin >> k;
			scanf("%lld", &k);
			up_data(x, y, 1, n, 1, 2, k % p);
		} else
		{
			ll out = query(x, y, 1, n, 1);
			// cout << out % p << endl;
			printf("%lld\n", out % p);
		}
	}
	return 0;
}
void build(ll l, ll r, ll id)
{
	if (l == r)
	{
		node[id] = num[l] % p;
		return ;
	}
	ll m = (l + r) >> 1;
	build(l, m, id << 1);
	build(m + 1, r, id << 1 | 1);
	push_up(id);
}
void push_up(ll id)
{
	node[id] = (node[id << 1] % p + node[id << 1 | 1] % p) % p;
}
void up_data(ll L, ll R, ll l, ll r, ll id, ll op, ll x)
{
	if (l >= L && r <= R)
	{
		if (op == 1)
		{
			node[id] = (node[id] % p * x % p) % p;
			mul[id] = (mul[id] % p * x % p) % p;
			add[id] = (add[id] % p * x % p) % p;
		} else
		{
			node[id] = (node[id] + x % p * (r - l + 1) ) % p;
			add[id] = (add[id] + x ) % p;
		}
		return ;
	}
	ll m = (l + r) >> 1;
	push_down(m - l + 1, r - m, id);
	if (L <= m)
		up_data(L, R, l, m, id << 1, op, x);
	if (R > m)
		up_data(L, R, m + 1, r, id << 1 | 1, op, x);
	push_up(id);

}
void push_down(ll lt, ll rt, ll id)
{
	node[id << 1] = (node[id << 1]   * mul[id]  + add[id]   * lt ) % p;
	node[id << 1 | 1] = (node[id << 1 | 1]   * mul[id]   + add[id]   * rt ) % p;
	add[id << 1] = (add[id << 1]   * mul[id]   + add[id]  ) % p ;
	add[id << 1 | 1] = (add[id << 1 | 1]   * mul[id]   + add[id]  ) % p;
	mul[id << 1] = (mul[id << 1]  * mul[id] ) % p;
	mul[id << 1 | 1] = (mul[id << 1 | 1] * mul[id] ) % p;
	mul[id] = 1;
	add[id] = 0;
}
ll query(ll L, ll R, ll l, ll r, ll id)
{
	if (l >= L && r <= R)
	{
		return node[id] % p;
	}
	ll m = (l + r) >> 1;
	ll ans = 0;
	push_down(m - l + 1, r - m, id);
	if (L <= m)
		ans = ans % p + query(L, R, l, m, id << 1) % p;
	if (R > m)
		ans = ans % p + query(L, R, m + 1, r, id << 1 | 1) % p;
	return ans % p;
}