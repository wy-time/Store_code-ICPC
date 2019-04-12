#include <iostream>
// #include<stdlib.h>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const ll maxn = 100005;
ll num[maxn];
ll node[maxn << 2], flag[maxn << 2];
void build(ll l, ll r, ll id);
void push_up(ll id);//更新当前节点
void up_data(ll L, ll R, ll l, ll r, ll add, ll id); //数据更新L,R是要更新的区间，l,r是当前所在区间
ll query (ll L, ll R, ll l, ll r, ll id);
void push_down(ll lt, ll rt, ll id); //向下更新标记
ll n;
int main()
{
	std::ios::sync_with_stdio(false);
	ll m;
	cin >> n >> m;
	ll i;
	wfor(i, 1, n + 1)
	{
		cin >> num[i];
	}
	build(1, n, 1);
	wfor(i, 0, m)
	{
		ll op, x, y, c;
		cin >> op;
		if (op == 1)
		{
			cin >> x >> y >> c;
			up_data(x, y, 1, n, c, 1);
		} else
		{
			cin >> x >> y;
			ll res = query(x, y, 1, n, 1);
			cout << res << endl;
		}
	}
	// system(pause);
	return 0;
}
void push_up(ll id)
{
	node[id] = node[id << 1] + node[id << 1 | 1];
	return ;
}
void build(ll l, ll r, ll id)
{
	if (l == r)
	{
		node[id] = num[l];
		return ;
	}
	ll m = (l + r) >> 1;
	build(l, m, id << 1);
	build(m + 1, r, id << 1 | 1);
	push_up(id);
}
void push_down(ll lt, ll rt, ll id)
{
	if (flag[id])
	{
		flag[id << 1] += flag[id];
		flag[id << 1 | 1] += flag[id];
		node[id << 1] += flag[id] * lt;
		node[id << 1 | 1] += flag[id] * rt;
		flag[id] = 0;
	}
}
void up_data(ll L, ll R, ll l, ll r, ll add, ll id)
{
	if (L <= l && R >= r)
	{
		node[id] += (r - l + 1) * add;
		flag[id] += add;
		return ;
	}
	ll m = (l + r) >> 1;
	push_down(m - l + 1, r - m, id);
	if (L <= m)
		up_data(L, R, l, m, add, id << 1);
	if (R > m)
		up_data(L, R, m + 1, r, add, id << 1 | 1);
	push_up(id);
}
ll query (ll L, ll R, ll l, ll r, ll id)
{
	if (l >= L && r <= R)
	{
		return node[id];
	}
	ll m = (l + r) >> 1;
	push_down(m - l + 1, r - m, id);
	ll ans = 0;
	if (L <= m)
		ans += query(L, R, l, m, id << 1);
	if (R > m)
		ans += query(L, R, m + 1, r, id << 1 | 1);
	return ans;
}