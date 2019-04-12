#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int main()
{
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	ll n, k;
	// cin>>n>>k;
	scanf("%lld%lld", &n, &k);
	ll i;
	priority_queue < ll, vector<ll>, greater<ll> >qu;
	wfor(i, 0, n)
	{
		ll t;
		// cin>>t;
		scanf("%lld", &t);
		qu.push(t);
	}
	ll add = 0;
	while (k--)
	{
		while (!qu.empty())
		{
			ll temp = qu.top();
			if (temp - add <= 0)
				qu.pop();
			else
				break;
		}
		if (!qu.empty())
		{
			ll temp = qu.top();
			printf("%lld\n", temp - add);
			qu.pop();
			add += temp - add;
		} else
			printf("0\n");
	}
	return 0;
}
