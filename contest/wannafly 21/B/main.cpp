#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
char ma[60][60];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int i, j;
		int begx, begy;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				cin >> ma[i][j];
				if (ma[i][j] == 'S')
				{
					begx = i;
					begy = j;
				}
			}
		}
		int res = -1;
		int flag = 0;
		for (i = begx; i < n; i++)
		{
			if (ma[i][begy] == '#')
			{
				flag = 1;
				break;
			}
		}
		// if (i == n)
		// {
		// 	res = max(res, n - 1);
		// }
		for (i = begx; i >= 0; i--)
		{
			if (ma[i][begy] == '#')
			{
				flag = 1;
				break;
			}
		}
		// if (i == -1)
		// {
		// 	res = max(res, n - 1);
		// }
		for (j = begy; j < m; j++)
		{
			if (ma[begx][j] == '#')
			{
				flag = 1;
				break;
			}
		}
		// if (j == m)
		// {
		// 	res = max(res, m - 1);
		// }
		for (j = begy; j >= 0; j--)
		{
			if (ma[begx][j] == '#')
			{
				flag = 1;
				break;
			}
		}
		// if (j == -1)
		// {
		// 	res = max(res, m - 1);
		// }
		if (flag)
			res = -1;
		else
			res = (n + m - 2);
		cout << res << endl;
	}
	return 0;
}
