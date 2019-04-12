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
ll num[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	int i;
	ll ans = 0;
	wfor(i, 0, n)
	{
		cin >> num[i];
	}
	mfor(i, n - 1, 0)
	{
		if (num[i] < 0)
			ans += num[i] * (i + 1);
	}
	wfor(i, 0, n)
	{
		if (num[i] > 0)
			ans += num[i];
	}
	cout << ans << endl;
	return 0;
}
