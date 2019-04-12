#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
#define lowbit(x) x&-x
void updata(int x, int add);
ll get_sum(int x);
ll ans[500005];
int n, m;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	int i;
	wfor(i, 0, n)
	{
		int t;
		cin >> t;
		updata(i + 1, t);
	}
	wfor(i, 0, m)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1)
		{
			updata(x, y);
		} else
		{
			ll res = get_sum(y) - get_sum(x - 1);
			cout << res << endl;
		}
	}
	return 0;
}
void updata(int x, int add)
{
	int i;
	for (i = x; i <= n; i += lowbit(i))
		ans[i] += add;
}
ll get_sum(int x)
{
	int i;
	ll sum = 0;
	for (i = x; i > 0; i -= lowbit(i))
		sum += ans[i];
	return sum;
}