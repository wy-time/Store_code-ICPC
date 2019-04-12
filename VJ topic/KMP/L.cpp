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
const int maxn = 100005;
int _next[2 * maxn];
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
		string s1, s2;
		cin >> s1 >> s2;
		int len2 = s2.size();
		int len1 = s1.size();
		int i;
		int table[30];
		wfor(i, 0, len1)
		{
			table[s1[i] - 'a'] = i;
		}
		string temp = s2;
		wfor(i, 0, len2)
		{
			temp[i] = s1[temp[i] - 'a'];
		}
		temp = s2 + "@" + temp;
		cal_next(temp);
		int lent = 2 * len2 + 1;
		string temps = s2;
		if (_next[lent - 1] == 0)
		{
			wfor(i, 0 , len2)
			{
				s2 += table[temps[i] - 'a'] + 'a';
			}
		}
		else if (_next[lent - 1] * 4 < lent - 1)
		{
			int beg = _next[lent - 1];
			wfor(i, beg , len2 - beg)
			{
				s2 += table[temps[i] - 'a'] + 'a';
			}
		} else if (_next[lent - 1] * 2 == lent - 1)
		{
			if (_next[len2 - 1] * 2 != len2)
			{
				int beg = _next[len2 - 1];
				int endx = len2 - beg > beg ? len2 - beg : len2;
				wfor(i, beg, endx)
				{
					s2 += table[temps[i] - 'a'] + 'a';
				}
			}
		}
		cout << s2 << endl;
	}
	return 0;
}
void cal_next(string s)
{
	int k = -1;
	int i;
	int len = s.size();
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