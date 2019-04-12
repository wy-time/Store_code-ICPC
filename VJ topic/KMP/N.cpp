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
int _next[205];
string s[4005];
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
		if (n == 0)
			break;
		int i;
		wfor(i, 0, n)
		{
			cin >> s[i];
		}
		int j, kk, l;
		int len = s[0].size();
		string temp = s[0];
		string ans = "";
		wfor(i, 0, len)
		{
			s[0] = temp;
			s[0] = s[0].substr(i);
			cal_next(s[0]);
			wfor(l, 1, len - i + 1)
			{
				int flag = 0;
				wfor(j, 1, n)
				{
					int k = -1;
					int flag2 = 0;
					int lent = s[j].size();
					wfor(kk, 0, lent)
					{
						while (k > -1 && s[0][k + 1] != s[j][kk])
							k = _next[k];
						if (s[0][k + 1] == s[j][kk])
							++k;
						if (k == l - 1)
						{
							flag++;
							flag2 = 1;
							break;
						}
					}
					if (flag2 != 1)
						break;
				}
				if (flag != n - 1)
					break;
				else
				{
					int len_ans = ans.size();
					if (l > len_ans)
						ans = s[0].substr(0, l);
					else if (l == len_ans)
						ans = min(s[0].substr(0, l), ans);
				}
			}
		}
		if (ans != "")
			cout << ans << endl;
		else
			cout << "IDENTITY LOST" << endl;
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
}