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
	int n, m, r;
	cin >> n >> m >> r;
	int i;
	int minn = 0x7f7f7f7f;
	int maxn = 0;
	wfor(i, 0, n)
	{
		int t;
		cin >> t;
		minn = min(minn, t);
	}
	wfor(i, 0, m)
	{
		int t;
		cin >> t;
		maxn = max(maxn, t);
	}
	if (minn >= maxn)
		cout << r << endl;
	else
	{
		int cnt = r / minn;
		r -= cnt * minn;
		r += maxn * cnt;
		cout << r << endl;
	}
	return 0;
}

