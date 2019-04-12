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
const int maxn = 0x7f7f7f;
struct tem
{
	int vis[25];
};
tem zhuang[maxn];
int dp[25][maxn];
struct st
{
	int a;
	int b;
	int s;
	int _max;
	int id;
};
struct rule
{
	bool operator()(const st&p, const st&q)
	{
		if (p._max != q._max)
		{
			return p._max < q._max;
		} else
			return p.id < q.id;
	}
};
st info[25];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	int i;
	wfor(i, 0, n)
	{
		cin >> info[i].a >> info[i].b >> info[i].s;
		int j;
		wfor(j, 0, info[i].s)
		{
			int temp;
			cin >> temp;
			info[i]._max = max(info[i]._max, temp);
		}
		info[i].id = i + 1;
	}
	sort(info, info + n, rule());
	// vis[0] = 1;
	// ll res = 0;
	// wfor(i, 0, n)
	// {
	// 	if (vis[info[i]._max] == 1)
	// 	{
	// 		if (info[i].a * (i + 1) + info[i].b >= 0)
	// 		{
	// 			res += info[i].a * (i + 1) + info[i].b;
	// 			vis[info[i].id] = 1;
	// 		} else
	// 			break;
	// 	}
	// }
	cout << res << endl;
	return 0;
}
