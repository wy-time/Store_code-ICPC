#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const ll maxn = 100005;
ll num[maxn];
ll node[maxn << 2];
ll add[maxn << 2];
ll mul[maxn << 2];
ll p;
void build(ll l, ll r, ll id);
void push_up(ll id)
{
	node[id] = (node[id << 1] + node[id << 1 | 1]) % p;
}
void up_data(ll L, ll R, ll l, ll r, ll id, ll op, ll x);
void push_down(ll lt, ll rt, ll id);
ll query(ll L, ll R, ll l, ll r, ll id);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll n;
	cin >> n >> p;
	ll i;
	wfor(i, 1, n + 1)
	{
		cin >> num[i];
	}
	fill(mul, mul + (maxn << 2), 1);
	build(1, n, 1);
	ll m;
	cin >> m;
	wfor(i, 0, m)
	{
		ll op, l, r, x;
		cin >> op >> l >> r;
		if (op != 3)
		{
			cin >> x;
			up_data(l, r, 1, n, 1, op, x);
		} else
		{
			ll res = query(l, r, 1, n, 1);
			cout << res << endl;
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
void up_data(ll L, ll R, ll l, ll r, ll id, ll op, ll x)
{
	if (l >= L && r <= R)
	{
		if (op == 1)
		{
			node[id] = node[id] % p * x % p;
			mul[id] = mul[id] % p * x % p;
			add[id] = add[id] % p * x % p;
		} else
		{
			node[id] = (node[id] + x % p * (r - l + 1)) % p;
			add[id] = (add[id] + x) % p;
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
	node[id << 1] = (node[id << 1] * mul[id] + add[id] * lt) % p;
	node[id << 1 | 1] = (node[id << 1 | 1] * mul[id] + add[id] * rt) % p;
	mul[id << 1] = mul[id << 1] * mul[id] % p;
	mul[id << 1 | 1] = mul[id << 1 | 1] % p * mul[id] % p;
	add[id << 1] = (add[id << 1] % p * mul[id] % p + add[id]) % p;
	add[id << 1 | 1] = (add[id << 1 | 1] % p * mul[id] % p + add[id]) % p;
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
	push_down(m - l + 1, r - m, id);
	ll ans = 0;
	if (L <= m)
		ans = (ans + query(L, R, l, m, id << 1)) % p;
	if (R > m)
		ans = (ans + query(L, R, m + 1, r, id << 1 | 1)) % p;
	return ans;
}