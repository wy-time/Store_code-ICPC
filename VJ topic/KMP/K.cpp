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
const int maxn = 200005;
const int mod = 10007;
int _next[maxn];
int ans[maxn];
void cal_next(string s);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		memset(ans, 0, sizeof(ans));
		int n;
		cin >> n;
		string s;
		cin >> s;
		cal_next(s);
		int i;
		int len = s.size();
		wfor(i, 0, len)
		{
			int temp = i;
			while (_next[temp] != 0)
			{
				ans[_next[temp]]++;
				temp = _next[temp] - 1;
			}
		}
		int res = n;
		wfor(i, 0, len)
		{
			res += ans[i];
			res %= mod;
		}
		cout << res << endl;;
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
	_next[i]++;
}