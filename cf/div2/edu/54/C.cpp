#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
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
		int d;
		cin >> d;
		if (d * d - 4 * d < 0)
			cout << "N" << endl;
		else
		{
			double b = (1.0 * d + sqrt(d * d - 4 * d)) / 2.0;
			if (b != 0)
			{
				cout << "Y " << fixed << setprecision(9) << b << " " << 1.0 * d / b << endl;
			} else
				cout << "Y " << fixed << setprecision(9) << b << " " << b << endl;
		}
	}
	return 0;
}
