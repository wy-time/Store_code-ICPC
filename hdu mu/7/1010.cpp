#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int mod = 1e9 + 7;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b, c, d, p, n;
		cin >> a >> b >> c >> d >> p >> n;
		ll ans[200] = {0};
		ans[1] = a;
		ans[2] = b;
		int i;
		wfor(i, 3, n)
		{
			ans[i] = c * ans[i - 2] % mod + d * ans[i - 1] % mod + n / i;
			ans[i]  = ans[i] % mod;
		}
		wfor(i, 1, n)
		cout << ans[i] << endl;
	}
	return 0;
}
