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
		int n;
		cin >> n;
		int i;
		int flag = 0;
		int a;
		cin >> a;
		int first = 1;
		int res = 1;
		wfor(i, 1, n)
		{
			int t;
			cin >> t;
			if (first)
			{
				if (a >= t)
					res = 0;
				first = 0;
			} else
			{
				if (a == t)
					res = 0;
				else if (a > t)
				{
					flag = 1;
				} else if (flag == 1 && a < t)
					res = 0;
			}
			a = t;
		}
		if (res == 1 && flag == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
