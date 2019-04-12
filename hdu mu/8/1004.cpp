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
		char ma[205][205];
		int h, w;
		cin >> h >> w;
		int flag = 1;
		if (h % 2 == 0 && w % 2 != 0)
		{
			int i, j;
			wfor(i, 0, h)
			{
				wfor(j, 0, w)
				{
					if (flag == 1)
					{
						ma[i][j] = '(';
					} else
						ma[i][j] = ')';
				}
				flag = flag * -1;
			}
		} else if (h % 2 != 0 && w % 2 == 0)
		{
			int i, j;
			wfor(i, 0, w)
			{
				wfor(j, 0, h)
				{
					if (flag == 1)
					{
						ma[j][i] = '(';
					} else
						ma[j][i] = ')';
				}
				flag = flag * -1;
			}
		} else if (h % 2 != 0 && w % 2 != 0)
		{
			int i, j;
			wfor(i, 0, h)
			{
				wfor(j, 0, w)
				{
					ma[i][j] = '(';
				}
			}
		} else
		{
			int i, j;
			wfor(i, 0, h)
			{
				wfor(j, 0, w)
				{
					if (flag == 1)
					{
						ma[i][j] = '(';
					} else
						ma[i][j] = ')';
				}
				flag = flag * -1;
			}
		}
		int i, j;
		wfor(i, 0, h)
		{
			wfor(j, 0, w)
			{
				cout << ma[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}