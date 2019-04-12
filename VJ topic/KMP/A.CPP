#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	int flag = 1;
	if (ch == '-')
		flag = -1;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	x *= flag;
}
int _next[10005];
int s[1000005];
int p[10005];
void cal_next(int s[10005], int len);
int main()
{
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	read(t);
	while (t--)
	{
		int n, m;
		read(n); read(m);
		int i;
		wfor(i, 0, n)
		read(s[i]);
		wfor(i, 0, m)
		read(p[i]);
		cal_next(p, m);
		int len = n;
		int len2 = m;
		int k = -1;
		int ans = -1;
		wfor(i, 0, len)
		{
			while (k > -1 && s[i] != p[k + 1])
				k = _next[k];
			if (s[i] == p[k + 1])
				++k;
			if (k == len2 - 1)
			{
				ans = i - k;
				break;
			}
		}
		if (ans != -1)
			ans++;
		cout << ans << endl;
	}
	return 0;
}
void cal_next(int s[10005], int len)
{
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
		if (s[i] == s[_next[i] + 1] && _next[i] + 1 != i)
			_next[i] = _next[k];
	}
}