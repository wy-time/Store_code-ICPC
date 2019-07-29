#include <iostream>
#include<algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
ll c[100005];
ll n;
typedef struct
{
	ll v;
	ll pos;
} st;
st num[100005];
struct rule
{
	bool operator() (const st &a , const st &b)
	{
		return a.v < b.v;
	}
};
ll lowbit(ll x)
{
	return x & -x;
}
void add(ll x, ll t)
{
	ll i;
	for (i = x; i <= n; i += lowbit(i))
		c[i] += t;
}
ll get_sum(ll x)
{
	ll i;
	ll sum = 0;
	for (i = x; i > 0; i -= lowbit(i))
		sum += c[i];
	return sum;
}
ll b[100005];
int main()
{
	std::ios::sync_with_stdio(false);
	ll x, y;
	// while (cin >> n >> x >> y)
	while (1)
	{
		n = 4, x = 1, y = 1;
		memset(c, 0, sizeof(c));
		memset(b, 0, sizeof(b));
		ll i;
		wfor(i, 1, n + 1)
		{
			cin >> num[i].v;
			num[i].pos = i;
		}
		sort(num + 1, num + n + 1, rule());
		ll res = 0;
		ll cnt = 1;
		wfor(i, 1, n + 1)
		{
			if (i != 1 && num[i].v != num[i - 1].v)
			{
				cnt++;
			}
			b[num[i].pos] = cnt;
		}
		wfor(i, 1, n + 1)
		{
			add(b[i], 1);
			res += i - get_sum(b[i]);
		}
		// cout << res << endl;
		cout << res*min(x, y) << endl;
	}
	return 0;
}
