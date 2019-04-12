#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int maxn = 200005;
ll node[maxn << 2];
void build(int l, int r, int id);
void push_up(int id);
void updata(int l, int r, int id, int pos, ll x);
ll query(int l, int r, int L, int R, int id);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int m; ll d;
	cin >> m >> d;
	int i;
	ll last = 0;
	int cnt = 1;
	wfor(i, 0, m)
	{
		char op; ll x;
		cin >> op >> x;
		if (op == 'A')
		{
			x = (x + last) % d;
			updata(1, 200001, 1, cnt, x);
			cnt++;
		} else
		{
			last = query(1, 200001, cnt - x, cnt - 1, 1);
			cout << last << endl;
		}
	}
	return 0;
}
void push_up(int id)
{
	node[id] = max(node[id << 1], node[id << 1 | 1]);
}
void build(int l, int r, int id)
{
	if (l == r)
	{
		node[id] = 0;
		return ;
	}
	int m = (l + r) >> 1;
	build(l, m, id << 1);
	build(m + 1, r, id << 1 | 1);
	push_up(id);
}
void updata(int l, int r, int id, int pos, ll x)
{
	if (l == r)
	{
		node[id] = x;
		return ;
	}
	int m = (l + r) >> 1;
	if (pos <= m)
		updata(l, m, id << 1, pos, x);
	else
		updata(m + 1, r, id << 1 | 1, pos, x);
	push_up(id);
}
ll query(int l, int r, int L, int R, int id)
{
	if (l >= L && r <= R)
	{
		return node[id];
	}
	int m = (l + r) >> 1;
	ll ans = 0;
	if (L <= m)
		ans = max(ans, query(l, m, L, R, id << 1));
	if (R > m)
		ans = max(ans, query(m + 1, r, L, R, id << 1 | 1));
	return ans;
}