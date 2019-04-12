#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int ma[2505][2505];
int dpr[2505][2505];
int dpl[2505][2505];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	freopen("in", "r", stdin);
	while (cin >> n >> m)
	{
		memset(dpr, 0, sizeof(dpr));
		memset(dpl, 0, sizeof(dpl));
		memset(ma, 0, sizeof(ma));
		int i, j;
		int res = 0;
		wfor(i, 1, n + 1)
		{
			wfor(j, 1, m + 1)
			{
				cin >> ma[i][j];
			}
		}
		int k;
		wfor(i, 1, n + 1)
		{
			wfor(j, 1, m + 1)
			{
				if (ma[i][j] == 1)
				{
					dpr[i][j] = 1;
					int t1 = 0x3f3f3f, t2 = 0x3f3f3f;
					wfor(k, 0, dpr[i - 1][j - 1])
					{
						if (ma[i - k - 1][j] == 1)
						{
							t1 = k;
							break;
						}
					}
					wfor(k, 0, dpr[i - 1][j - 1])
					{
						if (ma[i][j - k - 1] == 1)
						{
							t2 = k;
							break;
						}
					}
					dpr[i][j] += min(dpr[i - 1][j - 1], min(t1, t2));
				}
				res = max(res, dpr[i][j]);
			}
		}
		wfor(i, 1, n + 1)
		{
			wfor(j, 1, m + 1)
			{
				if (ma[i][j] == 1)
				{
					dpl[i][j] = 1;
					int t1 = 0x3f3f3f, t2 = 0x3f3f3f;
					wfor(k, 0, dpl[i - 1][j + 1])
					{
						if (ma[i - k - 1][j] == 1)
						{
							t1 = k;
							break;
						}
					}
					wfor(k, 0, dpl[i - 1][j + 1])
					{
						if (ma[i][j + k + 1] == 1)
						{
							t2 = k ;
							break;
						}
					}
					dpl[i][j] += min(dpl[i - 1][j + 1], min(t1, t2));
				}
				res = max(res, dpl[i][j]);
			}
		}
		cout << res << endl;
	}
	return 0;
}
