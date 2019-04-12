#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	ll n;
	cin >> n;
	ll i;
	set<ll> st;
	ll ans = 0;
	for (i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ll t = i;
			ll cnt = n / i;
			ans = (cnt * 2 + (cnt * (cnt - 1)) * t) / 2;
			st.insert(ans);
			cnt = n / (n / i);
			t = n / i;
			ans = (cnt * 2 + (cnt * (cnt - 1)) * t) / 2;
			st.insert(ans);
		}
	}
	set<ll>::iterator it;
	for (it = st.begin(); it != st.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;
}
