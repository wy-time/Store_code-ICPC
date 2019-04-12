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
int ans[1000005];
void cal_next(string s);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	int cnt = 0;
	while (t--)
	{
		cnt++;
		string s;
		cin >> s;
		cal_next(s);
		int len = s.size();
		int num = 0;
		while (_next[len - 1] != 0)
		{
			ans[num++] = len - _next[len - 1];
			len = _next[len - 1];
		}
		cout << "Case #" << cnt << ": " << num + 1 << endl;
		int res = 0;
		int i;
		wfor(i, 0, num)
		{
			res += ans[i];
			cout << res << " ";
		}
		cout << s.size() << endl;
	}
	return 0;
}
void cal_next(string s)
{
	int len = s.size();
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
	wfor(i, 0, len)
	_next[i]++;
}