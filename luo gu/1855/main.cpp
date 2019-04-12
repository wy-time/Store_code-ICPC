#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
struct st
{
	int m;
	int t;
};
int dp[205][205] = {0};
int main()
{
	std::ios::sync_with_stdio(false);
	int n, M, T;
	cin >> n >> M >> T;
	st a[105];
	int i;
	wfor(i, 0, n)
	{
		cin >> a[i].m >> a[i].t;
	}
	int j;
	int k;
	wfor(i, 0, n)
	{
		mfor(j, M, a[i].m)
		{
			mfor(k, T, a[i].t)
			{
				dp[j][k] = max(dp[j][k], dp[j - a[i].m][k - a[i].t] + 1);
			}
		}
	}
	cout << dp[M][T] << endl;
	return 0;
}
