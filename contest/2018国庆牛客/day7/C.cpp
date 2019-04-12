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
const double ex = 1e-6;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	while (n--)
	{
		double l, d;
		cin >> l >> d;
		cout << fixed << setprecision(6) << 1 - d*log(d / l) << endl;
	}
	return 0;
}
