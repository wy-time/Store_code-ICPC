#include <iostream>
#include <algorithm>
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
const int maxn = 5e4 + 5;
int num[maxn];
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
	int n;
	cin >> n;
	int i;
	int j;
	int minnum = 0x7f7f7f7f;
	int ans = 0;
	wfor(i, 0, n)
	{
		cin >> num[i];
		ans += num[i];
		minnum = min(minnum, num[i]);
	}
	int sum = ans;
	wfor(i, 0, n)
	{
		for (j = 2; j * j <= num[i]; j++)
		{
			if (num[i] % j == 0)
			{
				ans = min(ans, sum - minnum - num[i] + num[i] / j + minnum * j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
