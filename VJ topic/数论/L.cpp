#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ll;
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
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	cin >> t;
	int casecnt = 0;
	while (t--)
	{
		casecnt++;
		ll n;
		cin >> n;
		int i;
		int first = 1;
		cout << "Case " << casecnt << ": ";
		mfor(i, 9, 0)
		{
			if ((n * 10 - i) % 9 == 0)
			{
				if (first)
				{
					first = 0;
					cout << (n * 10 - i) / 9;
				} else
					cout << " " << (n * 10 - i) / 9;
			}
		}
		cout << endl;
	}
	return 0;
}
