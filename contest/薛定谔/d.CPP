#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int ma [1005][1005] = {0};
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		memset(ma, 0, sizeof(ma));
		int n, m, k;
		cin >> n >> m >> k;
		int i, j;
		wfor(i, 0, n)
		{
			wfor(j, 0, m)
			{
				cin >> ma[i][j];
				ma[i][j] == 0 ? ma[i][j] = 1 : ma[i][j] = 0;
			}
		}
		int ans = 1;
		wfor(i, 1, n)
		{
			wfor(j, 1, m)
			{
				if (ma[i][j] >= 1 )
				{
					ma[i][j] = min(ma[i - 1][j - 1], min( ma[i - 1][j], ma[i][j - 1])) + 1;
					ans = max(ans, ma[i][j]);
				}
			}
		}
		if (ans >= k)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
