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
		cin >> n >> m;
		if (n == m || m == 0 || m == 1)
		{
			cout << m << " " << m << endl;
		} else
		{
			int t = n - m;
			if (t / (m - 1) >= 1)
				cout << m << " " << 1 << endl;
			else
			{
				if (m % (t + 1) == 0)
					cout << m << " " << m / (t + 1) << endl;
				else
					cout << m << " " << m / (t + 1) + 1 << endl;
			}
		}
	}
	return 0;
}
