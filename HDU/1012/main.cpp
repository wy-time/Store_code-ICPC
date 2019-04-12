#include <iomanip>
#include <iostream>
#ifdef test
#include <cstdio>
#endif
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
	int i;
	cout << "n" << " " << "e" << endl;
	cout << "- -----------" << endl;
	double ans[20] = {0};
	cout << 0 << " " << 1 << endl;
	ans[0] = 1;
	int fac[20] = {0};
	fac[0] = 1;
	wfor(i, 1, 3)
	{
		fac[i] = fac[i - 1] * i;
		ans[i] = ans[i - 1] + 1.0 / fac[i];
		cout << i << " " << ans[i] << endl;
	}
	wfor(i, 3, 10)
	{
		fac[i] = fac[i - 1] * i;
		ans[i] = ans[i - 1] + 1.0 / fac[i];
		cout << fixed << setprecision(9) << i << " " << ans[i] << endl;
	}
	return 0;
}
