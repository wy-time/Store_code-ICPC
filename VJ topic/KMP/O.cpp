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
const int maxn = 1000005;
int _next[maxn];
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
		int len = s.size();
		cal_next(s);
		int cnt = 1;
		if (len % (len - _next[len - 1] - 1) == 0)
			cnt = len / (len - _next[len - 1] - 1);
		len = len / cnt;
		int i = 0, j = 1, k = 0;
		//最小表示法
		while (i < len && j < len && k < len)
		{
			int tem = s[(i + k) % len] - s[(j + k) % len];
			if (tem == 0)
				++k;
			else
			{
				if (tem < 0)
					j = j + k + 1;
				else
					i = i + k + 1;
				if (i == j)
					++j;
				k = 0;
			}
		}
		int rank1 = i < j ? i : j;
		//最大表示法
		i = 0, j = 1, k = 0;
		while (i < len && j < len && k < len)
		{
			int tem = s[(i + k) % len] - s[(j + k) % len];
			if (tem == 0)
				++k;
			else
			{
				if (tem < 0)
					i = i + k + 1;
				else
					j = j + k + 1;
				if (i == j)
					++j;
				k = 0;
			}
		}
		int rank2 = i < j ? i : j;
		cout << rank1 + 1 << " " << cnt << " " << rank2 + 1 << " " << cnt << endl;
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