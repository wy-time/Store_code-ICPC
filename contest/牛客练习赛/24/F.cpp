#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const ll mod = 19260817;
ll dp[50005];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int i, j;
	dp[0] = 1;
	wfor(i, 0, n)
	{
		int t;
		cin >> t;
		wfor(j, t, m + 1)
		{
			dp[j] += dp[j - t];
			if (dp[j] >= mod)
				dp[j] -= mod;
		}
	}
	ll res = 0;
	wfor(i, 1, m + 1)
	{
		res += dp[i];
		if (res >= mod)
			res -= mod;
	}
	cout << res << endl;
	return 0;
}
