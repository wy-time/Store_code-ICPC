#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
struct st
{
	ll n;
	ll m;
	ll pos;
	ll ans;
};
const ll maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
ll fac[maxn];
ll inv[maxn];
ll kuai[maxn];
st query[maxn];
struct rule
{
	bool operator()(const st &a, const st &b)
	{
		if (kuai[a.n] == kuai[b.n])
			return a.m < b.m;
		else
			return a.n < b.n;
	}
};
struct rule2
{
	bool operator()(const st &a, const st &b)
	{
		return a.pos < b.pos;
	}
};
ll ksm(ll a, ll b);
void init();
ll get_com(ll n, ll m);
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int i;
	init();
	int unit = sqrt(t);
	wfor(i, 1, t + 1)
	{
		cin >> query[i].n >> query[i].m;
		query[i].pos = i;
		kuai[i] = i / (unit + 1);
	}
	sort(query + 1, query + 1 + t, rule());
	wfor(i, 0, query[1].m + 1)
	{
		query[1].ans += get_com(query[1].n, i);
	}
	int l = query[1].n;
	int r = query[1]. m;
	wfor(i, 2, t + 1)
	{
		query[i].ans = query[i - 1].ans;
		while (l < query[i].n)
		{
			query[i].ans = (2 * query[i].ans % mod - get_com(l, r) + mod) % mod;
			l++;
		}
		while (l > query[i].n)
		{
			query[i].ans = ((query[i].ans + get_com(l - 1, r)) % mod * inv[2] % mod) % mod;
			l--;
		}
		while (r < query[i].m)
		{
			query[i].ans = (query[i].ans % mod + get_com(l, r + 1) % mod) % mod;
			r++;
		}
		while (r > query[i].m)
		{
			query[i].ans = (query[i].ans - get_com(l, r) + mod) % mod;
			r--;
		}
	}
	sort(query + 1, query + 1 + t, rule2());
	wfor(i, 1, t + 1)
	{
		cout << query[i].ans << endl;
	}
	return 0;
}
ll ksm(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans % mod * a % mod;
		a = a % mod * a % mod;
		b >>= 1;
	}
	return ans % mod;
}
void init()
{
	fac[0] = 1;
	int i;
	wfor(i, 1, maxn)
	{
		fac[i] = fac[i - 1] % mod * i % mod;
	}
	inv[maxn - 1] = ksm(fac[maxn - 1], mod - 2) % mod;
	mfor(i, maxn - 2, 0)
	{
		inv[i] = inv[i + 1] % mod * (i + 1) % mod;
	}
}
ll get_com(ll n, ll m)
{
	return (fac[n] * inv[m] % mod * inv[n - m] % mod) % mod;
}
