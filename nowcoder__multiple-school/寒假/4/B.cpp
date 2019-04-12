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
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	if (n == 1 && m > 2)
		cout << -1 << endl;
	else if (n > 2 && m == 1)
		cout << -1 << endl;
	else if (n % 2 != 0 && m % 2 != 0)
		cout << -1 << endl;
	else if (n == 1 && m == 2)
		cout << "RL";
	else if (n == 2 && m == 1)
		cout << "DU";
	else
	{
		if (n % 2 == 0)
		{
			int cnt = n - 1;
			while (cnt--)
				cout << 'D';
			cnt = n - 1;
			int flag = 1;
			int first = 1;
			while (cnt--)
			{
				int t = m - 1;
				if (flag == 1)
				{
					if (first)
					{
						first = 0;
					} else
					{
						t--;
						cout << 'U';
					}
					while (t--)
						cout << 'R';
					flag *= -1;
				} else
				{
					t--;
					cout << 'U';
					while (t--)
						cout << 'L';
					flag *= -1;
				}
			}
			cout << 'U';
			int t = m - 1;
			while (t--)
				cout << 'L';
		} else if (m % 2 == 0)
		{
			int cnt = n - 1;
			while (cnt--)
				cout << 'D';
			int flag = 1;
			cnt = m - 1;
			while (cnt--)
			{
				if (flag == 1)
				{
					cout << 'R';
					int t = n - 2;
					while (t--)
						cout << 'U';
					flag *= -1;
				} else
				{
					cout << 'R';
					int t = n - 2;
					while (t--)
						cout << 'D';
					flag *= -1;
				}
			}
			cout << 'U';
			cnt = m - 1;
			while (cnt--)
				cout << 'L';
		}
	}
	return 0;
}