#include <iostream>
#include <cstdio>
using namespace std;
#include <algorithm>
#include <cmath>
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(ll &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
struct st
{
	ll w;
	ll sum;
};
st mai[100005];
st fus[100005];
struct rule1
{
	bool operator()(const st&a, const st &b)
	{
		return a.w + b.sum > b.w + a.sum;
	}
};
struct rule2
{
	bool operator()(const st&a, const st &b)
	{
		return a.w - b.sum > b.w - a.sum;
	}
};
struct rule3
{
	bool operator()(const st&a, const st &b)
	{
		return a.w - a.sum > b.w - b.sum;
	}
};
struct rule4
{
	bool operator()(const st&a, const st &b)
	{
		return a.w + a.sum > b.w + b.sum;
	}
};
struct rule5
{
	bool operator()(const st&a, const st &b)
	{
		return a.w * a.sum + b.w > b.sum;
	}
};
struct rule6
{
	bool operator()(const st&a, const st &b)
	{
		return a.w * b.sum > b.w * a.sum;
	}
};
int main()
{
	// std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	ll t;
	// cin >> t;
	read(t);
	while (t--)
	{
		ll n, m, k;
		// cin >> n >> m >> k;
		read(n), read(m), read(k);
		int i;
		int j;
		wfor(i, 0, n)
		{
			// cin >> mai[i].w;
			read(mai[i].w);
			ll sum = 0;
			wfor(j, 0, k)
			{
				ll t;
				// cin >> t;
				read(t);
				sum += t;
			}
			mai[i].sum = sum;
		}
		wfor(i, 0, m)
		{
			cin >> fus[i].w;
			ll sum = 0;
			wfor(j, 0, k)
			{
				ll t;
				// cin >> t;
				read(t);
				sum += t;
			}
			fus[i].sum = sum;
		}
		ll res = 0;
		sort(mai, mai + n, rule2());
		sort(fus, fus + m, rule1());
		res = mai[0].w + fus[0].w + abs(mai[0].sum - fus[0].sum);
		wfor(i, 0, n)
		{
			res = max(res, mai[i].w + fus[0].w + abs(mai[i].sum - fus[0].sum));
		}
		wfor(i, 0, m)
		{
			res = max(res, mai[0].w + fus[i].w + abs(mai[0].sum - fus[i].sum));
		}
		sort(mai, mai + n, rule4());
		sort(fus, fus + m, rule3());
		res = max(mai[0].w + fus[0].w + abs(mai[0].sum - fus[0].sum), res);
		// sort(mai, mai + n, rule2());
		// sort(fus, fus + m, rule1());
		// res = max(mai[0].w - mai[0].sum + fus[0].w + fus[0].sum, res);
		// cout << res << endl;
		wfor(i, 0, n)
		{
			res = max(res, mai[i].w + fus[0].w + abs(mai[i].sum - fus[0].sum));
		}
		wfor(i, 0, m)
		{
			res = max(res, mai[0].w + fus[i].w + abs(mai[0].sum - fus[i].sum));
		}
		sort(mai, mai + n, rule6());
		sort(fus, fus + m, rule5());
		res = max(mai[0].w + fus[0].w + abs(mai[0].sum - fus[0].sum), res);
		wfor(i, 0, n)
		{
			res = max(res, mai[i].w + fus[0].w + abs(mai[i].sum - fus[0].sum));
		}
		wfor(i, 0, m)
		{
			res = max(res, mai[0].w + fus[i].w + abs(mai[0].sum - fus[i].sum));
		}
		printf("%lld\n", res);
	}
	return 0;
}
