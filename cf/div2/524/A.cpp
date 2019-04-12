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
	ll n, k;
	cin >> n >> k;
	ll a1 = (2 * n) % k == 0 ? 2 * n / k : 2 * n / k + 1;
	ll a2 = (5 * n) % k == 0 ? 5 * n / k : 5 * n / k + 1;
	ll a3 = (8 * n) % k == 0 ? 8 * n / k : 8 * n / k + 1;
	cout << a1 + a2 + a3 << endl;
	return 0;
}
