#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int i, j;
	ll ans[210][210] = {0};
	wfor(i, 0, n)
	{
		wfor(j, 1, m + 1)
		{
			cin >> ans[i][j];
		}
	}
	wfor(i, 1, n)
	{
		wfor(j, 1, m + 1)
		{
			ans[i][j] = max(ans[i - 1][j], max(ans[i - 1][j + 1], ans[i - 1][j - 1])) + ans[i][j];
		}
	}
	ll res = max(ans[n - 1][m / 2 + 1], max(ans[n - 1][m / 2], ans[n - 1][m / 2 + 2]));
	cout << res << endl;;
	return 0;
}
