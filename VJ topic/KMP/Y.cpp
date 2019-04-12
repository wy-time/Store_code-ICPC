#include <iostream>
#include <cstring>
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
int _next[5];
void cal_next(string s);
char s [70005];
int main()
{
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	string t = "doge";
	cal_next(t);
	int cnt = 0;
	while (gets(s) != NULL)
	{
		int len = strlen(s);
		int i;
		wfor(i, 0, len)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 'a' - 'A';
		}
		int k = -1;
		wfor(i, 0, len)
		{
			while (k > -1 && s[i] != t[k + 1])
				k = _next[k];
			if (s[i] == t[k + 1])
				++k;
			if (k == 3)
			{
				cnt++;
				k = _next[k];
			}

		}
	}
	cout << cnt << endl;
	return 0;
}
void cal_next(string s)
{
	int k = -1;
	int len = s.size();
	_next[0] = -1;
	int i;
	wfor(i, 1, len)
	{
		while (k > -1 && s[i] != s[k + 1])
			k = _next[k];
		if (s[i] == s[k + 1])
			++k;
		_next[i] = k;
	}
}