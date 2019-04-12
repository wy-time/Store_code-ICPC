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
int _next[100005];
char s[100005];
void cal_next();
int main()
{
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	// cin >> t;
	scanf("%d", &t);
	while (t--)
	{
		// string s;
		scanf("%s", s);
		cal_next();
		int len = strlen(s);
		if (len == 1)
			// cout << 1 << endl;
			printf("%d\n", 1);
		else
		{
			if (_next[len - 1] + 1 == len - 1)
				// cout << 0 << endl;
				printf("0\n");
			else if ((_next[len - 1] + 1) * 2 <= len)
			{
				printf("%d\n", len - (_next[len - 1] + 1) * 2);
				// cout << len - (_next[len - 1] + 1) * 2 << endl;
			} else
			{
				int t = (_next[len - 1] + 1) * 2 - len;
				int len2 = (_next[len - 1] + 1) - t;
				printf("%d\n", len2 - (len % len2 == 0 ? len2 : len % len2));
				// cout << len2 - len % len2 << endl;
			}
		}
	}
	return 0;
}
void cal_next()
{
	int len = strlen(s);
	int i;
	int k = -1;
	_next[0] = -1;
	wfor(i, 1, len)
	{
		while (k > -1 && s[i] != s[k + 1])
			k = _next[k];
		if (s[i] == s[k + 1])
			++k;
		_next[i] = k;
	}
}