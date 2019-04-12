#include <iostream>
#include<windows.h>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int ans[205][205];
	while (t--)
	{
		int n;
		int jiao = 0;
		cin >> n;
		if (n % 2 != 0)
		{
			cout << "impossible" << endl;
		} else
		{
			cout << "possible" << endl;
			int i, j;
			int t = 1;
			wfor(i, 0, n)
			{
				t = 1;
				wfor(j, 0, n)
				{
					if (n - j == i + 1)
					{
						t *= -1;
						if (jiao % 2 == 0)
						{
							ans[i][j] = 0;
							jiao++;
						} else
						{
							ans[i][j] = 1;
							jiao++;
						}

					} else
						ans[i][j] = t;
				}
			}
			wfor(i, 0, n)
			{
				wfor(j, 0, n - 1)
				{
					cout << ans[i][j] << " ";
				}
				cout << ans[i][j] << endl;
			}
		}
	}
	system("pause");
	return 0;
}
