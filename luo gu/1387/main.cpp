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
	int ma [105][105] = {0};
	// int ma2 [105][105] = {0};
	int i, j;
	wfor(i, 0, n)
	{
		wfor(j, 0, m)
		{
			cin >> ma[i][j];
			// ma2[i][j] = ma[i][j];
		}
	}
	int ans = 1;
	//int lans = 1;
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
//	wfor(i, 1, n)
//	{
//		mfor(j, m - 2, 0)
//	{
//		if (ma2[i][j] >= 1 && ma2[i][j + 1] >= 1 && ma2[i - 1][j] >= 1 && ma2[i - 1][j + 1] >= 1)
//			{
//			ma2[i][j] = ma2[i - 1][j + 1] + 1;
//				lans = max(lans, ma2[i][j]);
//			}
//		}
//	}
//	ans = min(ans, lans);
	cout << ans << endl;
	return 0;
}
