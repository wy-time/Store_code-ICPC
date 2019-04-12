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
const int maxn = 4e5 + 5;
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
	wfor(i, 0, n)
	{
		cin >> num[i];
	}
	int j = 0;
	wfor(i, n, 2 * n)
	{
		num[i] = num[j++];
	}
	int last = num[0];
	int ans = 0;
	if (num[0] == 1)
		ans = 1;
	int res = ans;
	wfor(i, 1, 2 * n)
	{
		if (last == num[i] && last == 1)
			ans++;
		else
		{
			last = num[i];
			res = max(res, ans);
			ans = 0;
			if (num[i] == 1)
				ans = 1;
		}
	}
	cout << res << endl;
	return 0;
}
