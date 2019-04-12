#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
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
		int x, y, n;
		cin >> x >> y >> n;
		int i;
		ll res = 0;
		wfor(i, 0, n)
		{
			int x1, y1;
			cin >> x1 >> y1;
			res += min(x1, min(x - x1, min(y1, y - y1)));
		}
		cout << res << endl;
	}
	return 0;
}
