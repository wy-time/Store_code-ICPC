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
const int maxn = 1e6 + 5;
int ans[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	ans[0] = 7 % 3;
	ans[1] = 11 % 3;
	int i;
	wfor(i, 2, maxn)
	{
		ans[i] = (ans[i - 1] + ans[i - 2]) % 3;
	}
	int n;
	while (cin >> n)
	{
		if (ans[n] == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
