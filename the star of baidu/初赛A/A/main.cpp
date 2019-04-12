#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int ans[1005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n)
	{
		int i;
		wfor(i, 0, n)
		{
			cin >> ans[i];
		}
		sort(ans, ans + n, greater<int>());
		if (n < 3)
		{
			cout << -1 << endl;
			continue;
		}
		int flag = 0;
		wfor(i, 0, n)
		{
			if (ans[i] >= ans[i + 1] + ans[i + 2])
				continue;
			else
			{
				cout << ans[i] + ans[i + 1] + ans[i + 2] << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << -1 << endl;
	}
	return 0;
}
