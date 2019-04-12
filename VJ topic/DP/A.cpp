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
int num[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	while (cin >> m >> n)
	{
		int i;
		wfor(i, 0, n)
		{
			cin >> num[i];
		}
		ll res = -0x7f7f7f7f7f;
		ll now = 0;
		wfor(i, 0, n)
		{
			if (now + num[i] > 0)
			{
				now += num[i];
				res = max(res, now);
			} else
			{
				now = 0;
			}
		}
		cout << res << endl;
	}
	return 0;
}
