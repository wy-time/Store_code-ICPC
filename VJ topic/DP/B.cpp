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
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n)
	{
		map <int, int>ma;
		int i;
		wfor(i, 0, n)
		{
			int t;
			cin >> t;
			if (ma.count(t) == 0)
			{
				ma.insert(make_pair(t, 1));
			} else
			{
				ma[t]++;
			}
		}
		map <int, int>::iterator it;
		int cnt = 0;
		int res = 0;
		for (it = ma.begin(); it != ma.end(); it++)
		{
			if (it->second > cnt)
			{
				res = it->first;
				cnt = it->second;
			}
		}
		cout << res << endl;
	}
	return 0;
}
