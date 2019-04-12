#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int mod = 998244353;
ll ksm(int a, int b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans % mod * a % mod;
		a = a % mod * a % mod;
		b >>= 1;
	}
	return ans;
}
ll  ans[100015];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	int i;
	ans[1] = 0;
	ans[2] = 0;
	wfor(i, 3, 100005)
	{
		ans[i] = ((i - 2) % mod * ans[i - 1] % mod + (i - 1) % mod * ans[i - 2] % mod);
		ans[i] -= ksm(-1, i);
	}
	while (t--)
	{
		ll n;
		cin >> n;
		cout << ans[n] % mod << endl;
	}
	return 0;
}
