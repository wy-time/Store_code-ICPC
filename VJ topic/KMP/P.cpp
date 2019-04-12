#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int _next[105];
void cal_next(string s);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n)
	{
		set<string> stmin;
		int cnt = 0;
		string s;
		int cas;
		wfor(cas, 0, n)
		{
			cin >> s;
			int i = 0, j = 1, k = 0;
			int len = s.size();
			cal_next(s);
			int lent = len;
			if (len % (len - _next[len - 1] - 1) == 0)
				lent = len - _next[len - 1] - 1;
			while (i < lent && j < lent && k < lent)
			{
				int temp = s[(i + k) % lent] - s[(j + k) % lent];
				if (temp == 0)
					++k;
				else
				{
					if (temp < 0)
						j += k + 1;
					else
						i += k + 1;
					if (i == j)
						++j;
					k = 0;
				}
			}
			int pos = i < j ? i : j;
			s += s;
			if (stmin.count(s.substr(pos, len)) == 0)
			{
				cnt++;
				stmin.insert(s.substr(pos, len));
			}
		}
		cout << cnt << endl;
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
}