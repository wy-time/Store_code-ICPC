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
	int t;
	cin >> t;
	while (t--)
	{
		map <int, int>ma;
		int n;
		cin >> n;
		int i;
		wfor(i, 0, n)
		{
			int temp;
			cin >> temp;
			if (ma.count(temp) == 0)
				ma.insert(make_pair(temp, 1));
			else
				ma[temp]++;
		}
		map <int, int>::iterator it;
		ll res = 0;
		for (it = ma.begin(); it != ma.end(); it++)
		{
			res += (*it).second;
			res -= 1;
		}
		cout << res << endl;
	}
	return 0;
}
