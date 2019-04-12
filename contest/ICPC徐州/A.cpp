#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 1e6 + 5;
// int vis [maxn];
const ll mod = 1e9 + 7;
ll ksm(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
ll dp[maxn];
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
		int n, k;
		cin >> n >> k;
		int i;
		dp[0] = 0;
		dp[1] = ksm(2, k);
		dp[2] = 10;
		ll m = ksm(2, k) ;
		for (i = 3; i <= n; i++)
		{
			// m = dp[i - 1];
			dp[i] = dp[i - 1] * (m - 2) + dp[i - 2] * (m - 1);
			dp[i] %= mod;
			// m++;

		}
		cout << dp[n] << endl;
	}
	return 0;
}
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// long long int dp[1100000], m, n, l, j, o, t, k = 1e9 + 7;
// long long  kuai(long long y) //求m(b%k)的y次方对k取模
// {
// 	if (y == 0) return 1; //如果幂指数为0，说明分完了，返回1
// 	else //否则呢。。就分它的指数（当然要判断次数奇偶）
// 	{
// 		long long temp;
// 		temp = kuai(y / 2); //递归核心，不断去求它的y/2的值
// 		if (y % 2 == 0) //说明是偶数
// 			return temp * temp % k;
// 		else //奇数
// 			return temp * temp * 2 % k; //要再乘一遍自己
// 	}
// }
// int main()
// {
// 	scanf("%lld", &t);
// 	while (t--)
// 	{
// 		memset(dp, 0, sizeof(dp));
// 		scanf("%lld%lld", &j, &o);
// 		dp[0] = 0;
// 		dp[1] = kuai(o);
// 		int p = kuai(o) - o, yi = 1, lp = kuai(o), w = kuai(yi) - 1;
// 		for (int x = 0; x < lp; x++)
// 		{
// 			dp[2] += p;
// 			//printf("%d %d\n",dp[2],p);
// 			if (x == w)
// 			{
// 				yi++;
// 				w = kuai(yi) - 1;
// 				p++;
// 			}
// 		}
// 		m = kuai(o) - 1;
// //printf("%d %d\n",dp[2],m);
// 		for (int x = 3; x <= j; x++)
// 		{
// 			dp[x] = dp[x - 1] * max(0ll, (m - 2)) + dp[x - 2] * m;
// 			dp[x] %= k;
// 			m++;
// 			//printf("%d %d %d %d\n",dp[x-1],dp[x],x,m);
// 		}
// 		printf("%lld\n", dp[j]);
// 	}
// }