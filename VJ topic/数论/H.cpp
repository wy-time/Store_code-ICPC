#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
struct info
{
	int two;
	int five;
};
const int maxn = 1e6 + 5;
info z1[maxn], z2[maxn];
void init()
{
	int i;
	int ans1 = 0, ans2 = 0;
	wfor(i, 1, maxn)
	{
		ans1 = 0, ans2 = 0;
		int tmp = i;
		while (tmp % 2 == 0)
		{
			ans1++;
			tmp /= 2;
		}
		tmp = i;
		while (tmp % 5 == 0)
		{
			ans2++;
			tmp /= 5;
		}
		z1[i].two = ans1;
		z1[i].five = ans2;
	}
	wfor(i, 1, maxn)
	{
		ans1 = 0, ans2 = 0;
		int tmp = i;
		while (1)
		{
			ans1 += tmp / 2;
			tmp /= 2;
			if (tmp == 0)
				break;
		}
		tmp = i;
		while (1)
		{
			ans2 += tmp / 5;
			tmp /= 5;
			if (tmp == 0)
				break;
		}
		z2[i].two = ans1;
		z2[i].five = ans2;
	}
}
int main()
{
	// std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	// cin >> t;
	read(t);
	int casecnt = 0;
	init();
	while (t--)
	{
		casecnt++;
		int n, r, p, q;
		// cin >> n >> r >> p >> q;
		read(n), read(r), read(p), read(q);
		int t1 = z1[p].two * q + z2[n].two - (z2[r].two + z2[n - r].two);
		int t2 = z1[p].five * q + z2[n].five - (z2[r].five + z2[n - r].five);
		int res = min(t1, t2);
		// cout << "Case " << casecnt << ": " << res << endl;
		printf("Case %d: %d\n", casecnt, res);
	}
	return 0;
}