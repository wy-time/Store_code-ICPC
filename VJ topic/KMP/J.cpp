// #include <iostream>
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// // void read(int &x) {
// // 	char ch = getchar(); x = 0;
// // 	for (; ch < '0' || ch > '9'; ch = getchar());
// // 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// // }
// const int maxn = 50005;
// void get_next(string s);
// void get_extend(string s, string s2);
// int _next[maxn];
// int extend[maxn];
// int ans;
// int main()
// {
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// 	string s1, s2;
// 	while (cin >> s1 >> s2)
// 	{
// 		ans = 0;
// 		get_next(s1);
// 		get_extend(s2, s1);
// 		if (ans != 0)
// 			cout << s1.substr(0, ans) << " " << ans << endl;
// 		else
// 			cout << ans << endl;
// 	}
// 	return 0;
// }
// void get_next(string s)
// {
// 	int len = s.size();
// 	int i;
// 	int p = 0;
// 	int a = 0;
// 	_next[0] = len;
// 	wfor(i, 1, len)
// 	{
// 		if (i >= p || i + _next[i - a] >= p)
// 		{
// 			if (i > p)
// 				p = i;
// 			while (p < len && s[p] == s[p - i])
// 				++p;
// 			_next[i] = p - i;
// 			a = i;
// 		} else
// 			_next[i] = _next[i - a];
// 	}
// }
// void get_extend(string s, string s2)
// {
// 	int len = s.size();
// 	int i;
// 	int a = 0; int p = 0;
// 	int len2 = s2.size();
// 	wfor(i, 0, len)
// 	{
// 		if (i >= p || i + _next[i - a] >= p)
// 		{
// 			if (i > p)
// 				p = i;
// 			while (p < len && p - i < len2 && s[p] == s2[p - i])
// 				++p;
// 			a = i;
// 			extend[i] = p - i;
// 		} else
// 			extend[i] = _next[i - a];
// 		ans = max(ans, extend[i]);
// 	}
// }
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
void cal_next(string s);
int _next[100005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		string s = s1 + "@" + s2;
		int len = s.size();
		cal_next(s);
		int len1 = s1.size();
		int len2 = s2.size();
		if (_next[len1 + len2] < len)
		{
			if (_next[len1 + len2] + 1 != 0)
				cout << s1.substr(0, _next[len1 + len2] + 1) << " " << _next[len1 + len2] + 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}
void cal_next(string s)
{
	int i;
	int len = s.size();
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