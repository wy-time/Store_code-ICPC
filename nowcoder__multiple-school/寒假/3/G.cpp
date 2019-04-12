#include <iostream>
#include <cstring>
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
ll dp [20][2];
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
	ll l, r;
	cin >> l >> r;
	int i;
	dp[0][0] = 1;
	dp[0][1] = 0;
	wfor(i, 1, 20)
	{
		dp[i][0] = dp[i - 1][0] * 9;
		dp[i][1] = dp[i - 1][1] * 10 + dp[i - 1][0];
	}
	int digit[20] = {0};
	int cnt = 0;
	// l++;
	int flag = 0;
	while (l)
	{
		digit[++cnt] = l % 10;
		l /= 10;
	}
	ll sum = 0;
	mfor(i, cnt, 1)
	{
		sum += digit[i] * dp[i - 1][1];
		if (flag)
			sum += digit[i] * dp[i - 1][0];
		else
		{
			if (digit[i] > 6)
			{
				sum += dp[i - 1][0];
			}
			if (digit[i] == 6)
				flag = 1;
		}
	}
	ll tans = sum;
	sum = 0;
	cnt = 0;
	flag = 0;
	memset(digit, 0, sizeof(digit));
	r += 1;
	while (r)
	{
		digit[++cnt] = r % 10;
		r /= 10;
	}
	mfor(i, cnt, 1)
	{
		sum += digit[i] * dp[i - 1][1];
		if (flag)
			sum += digit[i] * dp[i - 1][0];
		else
		{
			if (digit[i] > 6)
			{
				sum += dp[i - 1][0];
			}
			if (digit[i] == 6)
				flag = 1;
		}
	}
	cout << sum - tans << endl;
	return 0;
}
