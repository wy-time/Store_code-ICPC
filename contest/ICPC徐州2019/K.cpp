#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct PO
{
	int x;
	int y;
};
const int maxn = 1005;
PO point[maxn];
map<pair<int, int>, ll>ma;
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
		cin >> point[i].x >> point[i].y;
	}
	int j;
	ll maxnum = 0;
	wfor(i, 0, n)
	{
		wfor(j, i, n)
		{
			int x = point[i].x + point[j].x;
			int y = point[i].y + point[j].y;
			int gre = 0;
			if (i != j)
				gre = 2;
			else
				gre = 1;
			if (ma.count(make_pair(x, y)) == 0)
				ma.insert(make_pair(make_pair(x, y), gre));
			else
				ma[make_pair(x, y)] += gre;
			maxnum = max(maxnum, ma[make_pair(x, y)]);
		}
	}
	cout << n - maxnum << endl;
	return 0;
}
