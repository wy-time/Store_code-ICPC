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
int _next[maxn];
int ans[maxn];
void cal_next(string s);
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
		string s;
		cin >> s;
		cal_next(s);
		int len = s.size();
		if (_next[len - 1] != 0)
		{
			while (ans[_next[len - 1]] < 2 && _next[len - 1] != 0)
				len = _next[len - 1];
			if (ans[_next[len - 1]] >= 2)
				cout << _next[len - 1] << endl;
			else
				cout << 0 << endl;
		} else
			cout << 0 << endl;
	}
	return 0;
}
void cal_next(string s)
{
	int k = -1;
	int len = s.size();
	int i;
	_next[0] = -1;
	wfor(i, 1, len)
	{
		while (k > -1 && s[i] != s[k + 1])
			k = _next[k];
		if (s[i] == s[k + 1])
			++k;
		_next[i] = k;
	}
	wfor(i, 0, len)
	{
		ans[i] = 0;
		_next[i]++;
		int t = i + 1;
		while (_next[t - 1] * 2 > i + 1)
			t = _next[t - 1];
		if (_next[t - 1] != 0 )
			ans[_next[t - 1]]++;
	}
}