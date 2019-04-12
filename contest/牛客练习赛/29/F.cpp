#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 2e6 + 5;
int num[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int i;
	wfor(i, 0, n)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	wfor(i, 1, m + 1)
	{
		int j;
		wfor(j, 0, n)
		{
			int l, r = 0;
			wfor(l = 1 && )
		}
	}
	return 0;
}
