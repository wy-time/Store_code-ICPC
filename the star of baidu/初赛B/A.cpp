#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <algorithm>
#include <cstring>
// #include <vector>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
ll pre[200005];
// struct st
// {
// 	ll id;
// 	ll num;
// };
ll deg[200005];
// struct rule
// {
// 	bool operator()(const st&a,const st &b)
// 	{
// 		return a.num>b.num;
// 	}
// };
ll findx(ll x);
void join(ll a, ll b);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ll t;
	cin >> t;
	// vector<ll>
	while (t--)
	{
		memset(deg, 0, sizeof(deg));
		ll max_id = -1;
		ll max_deg = -1;
		ll n, m, k;
		cin >> n >> m >> k;
		ll i;
		wfor(i, 1, n + 1)
		{
			pre[i] = i;
		}
		wfor(i, 0, m)
		{
			ll t1, t2;
			cin >> t1 >> t2;
			t1 += 1, t2 += 1;
			deg[t1]++;
			deg[t2]++;
			if (deg[t1] > max_deg)
			{
				max_deg = deg[t1];
				max_id = t1;
			}
			if (deg[t2] > max_deg)
			{
				max_deg = deg[t2];
				max_id = t2;
			}
			join(t1, t2);
		}
		ll node = max_id;
		ll root = findx(node);
		ll cnt = 0;
		wfor(i, 1, n + 1)
		{
			if (findx(i) != root)
			{
				cnt++;
				join(root, i);
			}
		}
		ll res = 0;
		res += max_deg;
		res += cnt;
		if (k >= n - 1 - res)
		{
			res = n - 1;
		} else
		{
			res += k;
		}
		cout << res << endl;
	}
	return 0;
}
ll findx(ll x)
{
	ll t = x;
	while (t != pre[t])
		t = pre[t];
	ll i = x, j;
	while (pre[i] != t)
	{
		j = pre[i];
		pre[i] = t;
		i = j;
	}
	return t;
}
void join(ll a, ll b)
{
	ll a1 = findx(a);
	ll b1 = findx(b);
	pre[b1] = a1;
}