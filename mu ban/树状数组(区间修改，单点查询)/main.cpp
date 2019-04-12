#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int ans[500005];
int lowbit(int x);
void updata (int x, int y);
ll get_sum(int x);
int n, m;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	int i;
	int temp = 0;
	wfor(i, 1, n + 1)
	{
		int  t;
		cin >> t;
		updata(i, t - temp);
		temp = t;
	}
	wfor(i, 0, m)
	{
		int op, x, y, k;
		cin >> op;
		if (op == 1)
		{
			cin >> x >> y >> k;
			updata(x, k);
			updata(y + 1, -k);
		} else
		{
			cin >> x;
			ll res = get_sum(x);
			cout << res << endl;
		}

	}
	return 0;
}
int lowbit(int x)
{
	return x & -x;
}
void updata (int x, int y)
{
	int i;
	for (i = x; i <= n; i += lowbit(i))
		ans[i] += y;
}
ll get_sum(int x)
{
	int i;
	ll sum = 0;
	for (i = x; i > 0; i -= lowbit(i))
		sum += ans[i];
	return sum;
}