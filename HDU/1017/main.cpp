#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
// void dfs(int &cnt, int m, int n);
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
		int n, m;
		int casec = 0;
		while (cin >> n >> m)
		{
			if (n == 0 && m == 0)
			{
				if (t != 0)
					cout << endl;
				break;
			}
			int i, j;
			int cnt = 0;
			wfor(i, 1, n - 1)
			{
				wfor(j, i + 1, n)
				{
					if ((i * i + j * j + m) % (i * j) == 0)
						cnt++;
				}
			}
			casec++;
			cout << "Case " << casec << ": " << cnt << endl;
		}
	}
	return 0;
}
// void dfs(int &cnt, int m, int n)
// {

// }