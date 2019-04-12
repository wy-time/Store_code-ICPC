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
void cal__next(string s);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	string s1;
	string s2;
	cin >> s1 >> s2;
	cal__next(s2);
	int len = s1.size();
	int i;
	int len2 = s2.size();
	int k = -1;
	wfor(i, 0, len)
	{
		while (k > -1 && s2[k + 1] != s1[i])
			k = _next[k];
		if (s2[k + 1] == s1[i])
			k++;
		if (k == len2 - 1)
		{
			cout << i + 1 - k << endl;
			k = _next[k];
		}
	}
	wfor(i, 0, len2 - 1)
	{
		cout << _next[i] + 1 << " ";
	}
	cout << _next[i] + 1 << endl;
	return 0;
}
void cal__next(string s)
{
	int k = -1;
	_next[0] = -1;
	int i;
	int len = s.size();
	wfor(i, 1, len)
	{
		while (k > -1 && s[k + 1] != s[i])
		{
			k = _next[k];
		}
		if (s[k + 1] == s[i])
			++k;
		_next[i] = k;
	}
}