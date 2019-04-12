#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int  maxn = 500005;
int node[maxn << 2];
int num[maxn];
void push_up(int id);
void build(int l, int r, int id);
void up_data(int L, int R, int id, int add, int x);
ll query(int L, int R, int l, int r, int id);
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int i;
	wfor(i, 1, n + 1)
	{
		cin >> num[i];
	}
	build(1, n, 1);
	wfor(i, 0, m)
	{
		int x, y, op;
		cin >> op >> x >> y;
		if (op == 1)
		{
			up_data(1, n, 1, y, x);
		} else
		{
			ll sum = query(x, y, 1, n, 1);
			cout << sum << endl;
		}
	}
	return 0;
}
void push_up(int id)//更新节点信息，这里是求和
{
	node[id] = node[id << 1] + node[id << 1 | 1];
	return ;
}
void build(int l, int r, int id) //递归建树
{
	if (l == r)
	{
		node[id] = num[l];
		return ;
	}
	int m = (l + r) >> 1;
	build(l, m, id << 1);
	build(m + 1, r, id << 1 | 1);
	push_up(id);//更新节点信息
}
void up_data(int L, int R, int id, int add, int x) //单点修改
{
	if (L == R)
	{
		node[id] += add;
		return ;
	}
	int m = (L + R) >> 1;
	if (x <= m)
		up_data(L, m, id << 1, add, x);
	else
		up_data(m + 1, R, id << 1 | 1, add, x);
	push_up(id);
}
ll query(int L, int R, int l, int r, int id)
{
	if (l >= L && r <= R)
		return node[id];
	ll ans = 0;
	int m = (l + r) >> 1;
	if (L <= m)
		ans += query(L, R, l, m, id << 1);
	if (R > m)
		ans += query(L, R, m + 1, r, id << 1 | 1);
	return ans;
}