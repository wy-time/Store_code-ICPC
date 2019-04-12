#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(ll &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
#define lowbit(i) i&-i
ll const maxn = 1e5 + 5;
ll tree1[maxn];
ll tree2[maxn];
ll num[maxn];
ll n, q;
void up_data1(ll a, ll b)
{
	ll i;
	for (i = a; i <= n; i += lowbit(i))
		tree1[i] += b;
}
void up_data2(ll a, ll b)
{
	ll i;
	for (i = a; i <= n; i += lowbit(i))
		tree2[i] += b;
}
ll query1(ll l)
{
	ll i;
	ll sum = 0;
	for (i = l; i != 0; i -= lowbit(i))
		sum += tree1[i];
	return sum;
}
ll query2(ll l)
{
	ll i;
	ll sum = 0;
	for (i = l; i != 0; i -= lowbit(i))
		sum += tree2[i];
	return sum;
}
int main()
{
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	read(n); read(q);
	ll i;
	wfor(i, 1, n + 1)
	{
		read(num[i]);
		up_data1(i, num[i] * (n + 1 - i));
		up_data2(i, num[i]);
	}
	wfor(i, 0, q)
	{
		ll op;
		read(op);
		if (op == 1)
		{
			ll l, r;
			read(l); read(r);
			ll sum1 = query1(r) - query1(l - 1);
			ll sum2 = query2(r) - query2(l - 1);
			ll res = sum1 - sum2 * (n + 1 - l - (r - l + 1));
			printf("%lld\n", res);
		} else
		{
			ll a, b;
			read(a); read(b);
			up_data1(a, b * (n + 1 - a) - ((query1(a) - query1(a - 1))));
			up_data2(a, b - num[a]);
			num[a] = b;
		}
	}
	return 0;
}
