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
char s[100005];
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	while (cin >> s)
	{
		if (s[0] == '0')
			break;
		unsigned long long t = 0;
		int len = strlen(s);
		int i;
		wfor(i, 0, len)
		{
			t += s[i] - '0';
		}
		int res = t % 9;
		if (res == 0)
			res = 9;
		cout << res << endl;
	}
	return 0;
}
