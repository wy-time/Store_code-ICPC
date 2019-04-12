#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int card[5];
int dp[45][45][45][45];
int ma[400];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int i;
	wfor(i, 0, n)
	{
		cin >> ma[i];
	}
	wfor(i, 0, m)
	{
		int t;
		cin >> t;
		card[t]++;
	}
	int j, k, l, p;
	// wfor(i, 0, n)
	// {
	dp[0][0][0][0] = ma[0];
	wfor(j, 0, card[1] + 1)
	{
		wfor(k, 0, card[2] + 1)
		{
			wfor(l, 0, card[3] + 1)
			{
				wfor(p, 0, card[4] + 1)
				{
					int t = ma[j + k * 2 + l * 3 + p * 4];
					if (j > 0)
						dp[j][k][l][p] = max(dp[j][k][l][p], dp[j - 1][k][l][p] + t);
					if (k > 0)
						dp[j][k][l][p] = max(dp[j][k][l][p], dp[j][k - 1][l][p] + t);
					if (l > 0)
						dp[j][k][l][p] = max(dp[j][k][l][p], dp[j][k][l - 1][p] + t);
					if (p > 0)
						dp[j][k][l][p] = max(dp[j][k][l][p], dp[j][k][l][p - 1] + t);
				}
			}
		}
	}
	cout << dp[card[1]][card[2]][card[3]][card[4]] << endl;
	// }
	return 0;
}
