#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
// ll fib[100];
const int maxn = 1e6 + 5;
char s[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	cin >> s;
	int len = strlen(s);
	if ((s[len - 1] - '0') % 2 == 0)
		cout << 1 << endl;
	else
		cout << -1 << endl;
	return 0;
}
