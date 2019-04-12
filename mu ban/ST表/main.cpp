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
const int maxn = 100005;
int num[maxn];
int ans[maxn][20];
int _2pw[21];
int _2log[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int n, m;
	// cin >> n >> m;
	read(n), read(m);
	int i;
	_2pw[0] = 1;
	wfor(i, 1, 21)
	{
		_2pw[i] = _2pw[i - 1] * 2;
	}
	_2log[0] = -1;
	_2log[1] = 0;
	wfor(i, 2, n + 1)
	{
		_2log[i] = _2log[i / 2] + 1;
	}
	wfor(i, 1, n + 1)
	{
		read(num[i]);
	}
	wfor(i, 1, n + 1)
	{
		ans[i][0] = num[i];
	}
	int j;
	wfor(j, 1, _2log[n] + 1)
	{
		wfor(i, 1, n + 1)
		{
			if (i + _2pw[j - 1] <= n)
				ans[i][j] = max(ans[i][j - 1], ans[i + _2pw[j - 1]][j - 1]);
		}
	}
	wfor(i, 0, m)
	{
		int l, r;
		// cin >> l >> r;
		read(l); read(r);
		int t = _2log[r - l + 1];
		printf("%d\n", max(ans[l][t], ans[r - _2pw[t] + 1][t]));
	}
	return 0;
}
