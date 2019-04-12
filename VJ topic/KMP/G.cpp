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
int _next[1000005];
void cal_next(string s);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	string s;
	while (cin >> s)
	{
		if (s[0] == '.')
			break;
		cal_next(s);
		int len = s.size();
		if (_next[len - 1] == len - 1)
			cout << s.size() << endl;
		else
		{
			while (_next[len - 1] * 2 >= len)
			{
				len -= _next[len - 1];
			}
			if (s.size() % len == 0)
				cout << s.size() / len << endl;
			else
				cout << 1 << endl;
		}
	}
	return 0;
}
void cal_next(string s)
{
	int i;
	int k = -1;
	_next[0] = -1;
	int len = s.size();
	wfor(i, 1, len)
	{
		while (k > -1 && s[i] != s[k + 1])
			k = _next[k];
		if (s[i] == s[k + 1])
			++k;
		_next[i] = k;
	}
	wfor(i, 0, len)
	_next[i]++;
}